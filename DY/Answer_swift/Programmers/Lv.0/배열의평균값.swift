import Foundation

func solution(_ numbers:[Int]) -> Double {
    var sum = numbers.reduce(0, +)
    return Double(sum)/Double(numbers.count)
}
