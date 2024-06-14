import Foundation

func solution(_ money:Int) -> [Int] {
    var answer: [Int] = []
    answer.append(money / 5500)
    answer.append(money % 5500)
    return answer
    // return [money / 5500, money % 5500] -> 한 줄로 풀기 가능
}
