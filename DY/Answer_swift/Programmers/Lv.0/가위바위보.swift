import Foundation

func solution(_ rsp:String) -> String {
    var rival = ["2" : "0", "0" : "5", "5" : "2"]
    return rsp.map{rival[String($0)]!}.joined()
}
