//
//  ViewController.swift
//  Syslink
//
//  Created by Suphawat on 28/3/2563 BE.
//  Copyright © 2563 VAARI. All rights reserved.
//

import UIKit
import WebKit
import SafariServices
import Alamofire
import SKActivityIndicatorView


class ViewController: UIViewController,UINavigationControllerDelegate {
    @IBOutlet weak var webView: WKWebView!
    var url: URL?
    var credential: (username: String, password: String)?


    let OUID = "WL4JP7EHSZY63IOQTXFF"
    let username = "admin"
    let password = "888888"

    var mDevice: OBDeviceManager?
    var initReady = false
    var errorResponse = false

    override func viewDidLoad() {
        super.viewDidLoad()
        SKActivityIndicator.spinnerColor(UIColor(red: 255/255.0, green: 165/255.0, blue: 20/255.0, alpha: 1))
        SKActivityIndicator.show("", userInteractionStatus: false)
        initSDK()
        webView.navigationDelegate = self
        self.webView.frame = self.view.bounds

        // Do any additional setup after loading the view.
    }
    override func viewWillAppear(_ animated: Bool) {

    }
    func loadWebView() {
        if let url = url {
            let request = URLRequest(url: url)
            webView.load(request)
        }
    }

    func initSDK() {

        initReady = OBDeviceManager.initializeSDK()

        NotificationCenter.default.addObserver(self, selector: #selector(ChangeNotification(notification:)), name: NSNotification.Name(rawValue: NOTIFICATION_P2P_STATUS_CHANGE), object: nil)

        let info = CameraInfo()
        info.sid = OUID
        info.name = "AP-Test"
        info.setIDPassword(username, password: password)
        info.http_PORT = 80
        info.rtsp_PORT = 554

        mDevice = OBDeviceManager(info)

        onNetworkChange()
    }
    @IBAction func tapOnBack(_ sender: UIButton) {
        if let navigation = self.navigationController{
            navigation.popViewController(animated: true)
        }else{
            self.dismiss(animated: true, completion: {

            })
        }
    }

    @objc func onNetworkChange() {
        if let networkReachabilityManager = NetworkReachabilityManager() {
            let mStatus: M2MNetworkStatus = {
                if networkReachabilityManager.isReachableOnWWAN {
                    return .NetworkStatusReachableViaWWAN
                }
                if networkReachabilityManager.isReachableOnEthernetOrWiFi {
                    return .NetworkStatusReachableViaWiFi
                }

                return .NetworkStatusNotReachable
            } ()

            mDevice?.onNetworkChange(mStatus)
        }
    }

    @objc func ChangeNotification(notification: Notification) {
        print(notification)

        if let userInfo = notification.userInfo {
            if let type = userInfo[NOTIFICATION_KEY_TYPE] as? Int {
                print(type)
                DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 8.0) { // Change `2.0` to the desired number of seconds.
                    // Code you want to be delayed
                    SKActivityIndicator.dismiss()
                    self.errorResponse = false
                    if let mDevice = self.mDevice, mDevice.getP2PType() > 0 {
                        let port = mDevice.getLocalPort(80)

                        guard let url = URL(string: "http://127.0.0.1:\(port)") else {
                            return
                        }
                        self.url = url
                        self.credential = (username: self.username, password: self.password)
                        self.loadWebView()
                    }else{
                        self.errorResponse = true
                        print("error")
                    }
                }
            }

        }

    }

}
extension ViewController: WKNavigationDelegate {
    func webView(_ webView: WKWebView, didReceive challenge: URLAuthenticationChallenge, completionHandler: @escaping (URLSession.AuthChallengeDisposition, URLCredential?) -> Void) {
        if challenge.protectionSpace.host == "127.0.0.1" {
            if let credential = credential {
                let urlCredential = URLCredential(user: credential.username, password: credential.password, persistence: .none)

                completionHandler(.useCredential, urlCredential)
            } else {
                completionHandler(.performDefaultHandling, nil)
            }
        }
    }
}
