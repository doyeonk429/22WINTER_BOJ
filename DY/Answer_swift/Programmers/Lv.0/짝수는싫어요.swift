import Foundation

func solution(_ n:Int) -> [Int] {
    return Array<Int>(1...n).filter{ $0 % 2 != 0}
}
