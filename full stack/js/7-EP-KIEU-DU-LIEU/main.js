// xuất thông báo cho người dùng nhập vào số a
let numberA = prompt("Mời anh em nhập vào number: ");

// check thử loại kiểu biến nuberA
console.log(typeof numberA);

// thử thực hiện phép tính toán (nếu chưa ép kiểu giữ liệu)
let numberB = 5;

console.log(typeof numberB);

// cộng A với B
let tong = numberA + numberB;
console.log(` kết quả A + B = ${tong}`);
console.log(typeof tong);
// vd a = 8 , kết quả 85 --> sai , js hiểu là đang cộng chuỗi
// các phép tính khác 

console.log(`A-B= %s`, numberA - numberB);
console.log(`A-B= %s`, numberA * numberB);
console.log(`A-B= %s`, numberA / numberB);
console.log(`A-B= %s`, numberA % numberB);

// ép kiểu dư liệu người dùng prompt
// xuất thông báo cho người dùng nhập vào số C
let numberC = parseInt(prompt("Mời anh em nhập vào numberC: "));
console.log(numberC);
console.log(typeof numberC);
console.log(typeof numberC + numberB);

// hoặc đơn giản hơn ta dùng hàm number() để éo --> kiểu dữ liệu number
let numberD = Number(prompt("Mời anh em nhập vào numberD: "));
console.log(numberD);
console.log(typeof numberD);
console.log(numberD + numberB);