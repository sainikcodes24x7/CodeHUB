var largestPerimeter = function(nums) {
    let arr = [];
    let currentMax = 0;
    nums.sort((a, b) => a - b);
   
    for (let num of nums) {
        if (arr.length < 2) {
            arr.push(num);
            continue;
        }
        
        arr.push(num);
        if (isValid(arr)) {
            currentMax = getPerimeter(arr);
        }
        arr.shift();
 
    }
    return currentMax;

};

function isValid(arr) {
    if (arr[0] + arr[1] <= arr[2]) return false;
    if (arr[2] - arr[0] >= arr[1]) return false;
    return true;
}

function getPerimeter(arr) {
    return arr[0] + arr[1] + arr[2];
}