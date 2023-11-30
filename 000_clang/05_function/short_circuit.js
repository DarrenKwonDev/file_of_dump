let i = 0;
let j = 0;
let k = 0;

// short circuit evaluation
if (++i || (++j && ++k)) {
    console.log("true");
}

console.log(i, j, k); // 1 0 0
