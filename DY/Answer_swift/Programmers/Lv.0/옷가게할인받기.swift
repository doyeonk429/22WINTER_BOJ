import Foundation

func solution(_ price:Int) -> Int {
    if price >= 100000 && price < 300000{
        return Int(trunc(Double(price)*0.95))
    } else if price >= 300000 && price < 500000 {
        return Int(trunc(Double(price)*0.9))
    } else if price >= 500000 {
        return Int(trunc(Double(price)*0.8))
    } else {
        return price
    }
}
