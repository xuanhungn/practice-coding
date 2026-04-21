//1. Toán tử gán (=) Dùng để gán giá trị cho biến 
let x = 10; // Biến x được gán giá trị bằng 10
let y = 5; // Biến y được gán giá trị 5
let z = x + y; //  Biến z được gán giá trị tổng  x và y 
console.log(x);
console.log(y);
console.log(z);

// Gán +=, *=, /=, %=
console.log("Kết quả gán +=, *=, /=, %= ");
let m = 10;
m += 5; // Tương đương với m = m + 5;
console.log(m);

let n = 8;
n -= 3; // tương đương với n = n - 3
console.log(n);

let p = 6;
p *= 2; // tương đương với p = p * 2
console.log(p);

let q = 9;
q /= 3; // tương đương với q = q / 3
console.log(q);

let r = 4;
r %= 3; // tương đường với r = r % 3
console.log(r);

// bài tập
let e = 5;
let f = 2;
e -= (f += 1);
console.log(`e = ${e}`);

// BÀI TIẾP THEO 10.TOÁN TỬU TĂNG GIẢM