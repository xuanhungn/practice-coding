let a = 3;
let b = 3;
let c = "3"

console.log(typeof b);
console.log(typeof c);

// các phép so sánh thông thường giống toán học
console.log(a > b);
console.log(a < b);
console.log(a <= b);
console.log(a >= b);
console.log(a != b);
console.log(c != b); // lưu ý 

// so sánh == (không quan tâm đến kiểu của biến)
console.log(a == b);
console.log(c == b);

// so sánh Tuyệt Đối (===) So sánh giá trị và kiểu dữ liệu.
console.log(a === b);
console.log(c === b);

console.log("Phần 2");
console.log(a != b);
console.log(c != b); // không quan tâm đến kiểu của biến

console.log(a !== b);
console.log(c !== b);