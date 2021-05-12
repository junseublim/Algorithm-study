
let used = [];
for (let i = 1; i <= 10000; i++) {
    let q = [i];
    //console.log("i: ", i);
    while (q.length != 0) {
        let num = q.shift();
        let newNum = num;
        while (num > 0) {
            let temp = num % 10;
            num /= 10;
            num = parseInt(num);
            newNum += temp;
        }

        if (newNum > 10000) continue;
        if (newNum in used) continue;
        //console.log(newNum);
        used[newNum] = 1;
        q.push(newNum);
    }
}

console.log(used)
for (let i = 1; i <= 10000; i++) {
    if (!(i in used)) {
        console.log(i);
    }
}