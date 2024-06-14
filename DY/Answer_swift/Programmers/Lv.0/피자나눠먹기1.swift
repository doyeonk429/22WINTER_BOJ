import Foundation

func solution(_ n:Int) -> Int {
    var result = 1
    while result * 7 / n < 1 {
        result += 1
    }
    return result
}
