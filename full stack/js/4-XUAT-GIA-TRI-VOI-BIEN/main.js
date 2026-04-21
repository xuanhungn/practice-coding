let soA = 25;
let soB = 5;

// cách 1
console.log("Căn bậc hai của " + soA + " là: " + soB);
// cách 2
console.log("Căn bậc hai của", soA, "là:", soB);
// cách 3
console.log(`Căn bậc hai của ${soA} là: ${soB}`);
// cách 4
console.log(`Căn bậc hai của %d là %d `, soA, soB);

// bài tập
let a = 4,
    b = 3,
    kq = a * b;

// cách 1 
console.log("Kết quả: " + a + " nhân với " + b + " bằng " + kq);
// cách 2
console.log("Kết quả:", a, "nhân với", b, "bằng", kq);
// cách 3
console.log(`Kết quả: ${a} nhân với ${b} bằng ${kq}`);
// cách 4
console.log(`Kết quả: %s nhân với %s bằng %s`, a, b, kq);