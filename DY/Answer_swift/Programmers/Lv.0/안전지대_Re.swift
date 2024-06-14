import Foundation

func solution(_ board:[[Int]]) -> Int {
    var board = board
    let n = board.count
    
    let zones = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
    
    for i in 0..<n {
        for j in 0..<n {
            if board[i][j] == 1 {
                for dir in zones {
                    let newX = i + dir[0]
                    let newY = j + dir[1]
                    
                    if (0...n-1) ~= newX && (0...n-1) ~= newY {
                        if board[newX][newY] == 0 {
                            board[newX][newY] = -1
                        }
                    }
                }
            }
        }
    }
    
    return board.flatMap{ $0 }.filter{ $0 == 0 }.count
}
