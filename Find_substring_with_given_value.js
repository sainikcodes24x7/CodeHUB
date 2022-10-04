/**
 * @param {string} s
 * @param {number} power p
 * @param {number} modulo m
 * @param {number} k
 * @param {number} hashValue
 * @return {string}
 */
var subStrHash = function(s, p, m, k, hashValue) {
    p = BigInt(p);
    m = BigInt(m);
    hashValue = BigInt(hashValue);
    let tmp = 0n, res = 0, pk = 1n, n = s.length;
    for (let i = n-1; i >= 0; i--) {
        tmp = (tmp * p + BigInt(s[i].charCodeAt() - 96)) % m;
        if (i + k >= n) pk = pk * p % m;
        else tmp = (tmp - (BigInt(s[i+k].charCodeAt() - 96) * pk % m) + m) % m;
        if (tmp === hashValue) res = i;
    }
    return s.slice(res, res + k);
    // Avijit Sen
    // ashavijit
};
