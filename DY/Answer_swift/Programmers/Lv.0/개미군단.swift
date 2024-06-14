import Foundation

func solution(_ hp:Int) -> Int {
    var hp = hp // hp에서 계속 깎아야함
    var result = 0 // 최종 데리고 나갈 개미수
    for i in [5, 3, 1] { // 장군(5), 병정(3), 일(1)
        result += hp / i // 장군으로 먼저 나누고, 그 나머지를 hp로 재설정. 병정 -> 일 순으로 반복
        hp %= i
    }
    return result
}
