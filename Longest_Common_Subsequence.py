def lcs(S1, S2, m, n):
    Matrix = [[0 for x in range(n+1)] for x in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                Matrix[i][j] = 0
            elif S1[i-1] == S2[j-1]:
                Matrix[i][j] = Matrix[i-1][j-1] + 1
            else:
                Matrix[i][j] = max(Matrix[i-1][j], Matrix[i][j-1])

    index = Matrix[m][n]

    Subsequence = [""] * (index)

    i = m
    j = n
    while i > 0 and j > 0:

        if S1[i-1] == S2[j-1]:
            Subsequence[index-1] = S1[i-1]
            i -= 1
            j -= 1
            index -= 1

        elif Matrix[i-1][j] > Matrix[i][j-1]:
            i -= 1
        else:
            j -= 1

    print("First String : " + S1 + "\nSecond String : " + S2)
    print("Longest Common Subseque: " + "".join(Subsequence)+"\nLength: "+str(len(Subsequence)))