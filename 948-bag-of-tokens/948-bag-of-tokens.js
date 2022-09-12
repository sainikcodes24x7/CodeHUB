const countPoints = (tokens, P) => {
  let [i, score, sum] = [0, 0, 0];
  for (i; sum + tokens[i] <= P; score++, i++) {
    sum += tokens[i];
  }
  return score;
}

const bagOfTokensScore = (tokens, P, max = 0) => {
  const len = tokens.length;
  if (max === 0) tokens.sort((a, b) => a - b);
  if (len === 0) return max;
  const score = countPoints(tokens, P);
  if (score > max) max = score;
  return P > tokens[0]
    ? bagOfTokensScore(tokens.slice(1, len - 1), P - tokens[0] + tokens[len - 1], max)
    : max;
};