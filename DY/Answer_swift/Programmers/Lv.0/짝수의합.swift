import Foundation

func solution(_ n:Int) -> Int {
    var a = 0
    for e in stride(from: 0, through: n, by: 2) {
        a += e
    }
    return a
}
