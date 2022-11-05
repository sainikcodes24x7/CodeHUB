func findWords(board [][]byte, words []string) []string {
    m, n := len(board), len(board[0])
    hash := make(map[string]*Item)

    for i := range words {
        s := ""
        for j := range words[i] {
            s += string(words[i][j])
            _, ok := hash[s]
            if !ok {
                hash[s] = &Item{}
            }
            hash[s].reference++
        }
        hash[s].endOfWord = true
    }

    directions := [][]int{{1,0}, {0,1}, {-1,0}, {0,-1}}
    var answer []string

    remove := func(word string) {
        s := ""
        for i := range word {
            s += string(word[i])
            _, ok := hash[s]
            if !ok {
                break
            }
            hash[s].reference--
            hash[s].endOfWord = false
            if hash[s].reference == 0 {
                delete(hash, s)
            }
        }
    }

    var helper func(int, int, string)
    helper = func(r, c int, word string) {
        ch := board[r][c]

        if ch == '#' || hash[word] == nil {
            return
        } else if hash[word].endOfWord {
            answer = append(answer, word)
            remove(word)
        }

        board[r][c] = '#'

        for _, d := range directions {
            rr, cc := r + d[0], c + d[1]

            if rr >= 0 && cc >= 0 && rr < m && cc < n && board[rr][cc] != '#' {
                helper(rr, cc, word + string(board[rr][cc]))
            }
        }

        board[r][c] = ch
    }

    for i := range board {
        for j := range board[i] {
            helper(i, j, string(board[i][j]))
        }
    }

    return answer
}

type Item struct {
    reference int
    endOfWord bool
}