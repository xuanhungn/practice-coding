// dùng để tăng giảm giá trị của một biến đơn vị.
let a = 99;
let b = 10;
let c = 77;
let d = 88;

a++;
b--;
++c;
--d;

// xuất kết quả
console.log(a);
console.log(b);
console.log(c);
console.log(d);

// 2. Trường hợp phức tạp.
let x = 1;
let y = 2;
let z = x++ - ++y + 1;
console.log(x);
console.log(y);
console.log(z);

// a++, a-- (viết phía sau biến) => Postjix
// ++a, --a (viết phía trước biến) => Prejix 

// ưu tiên tính toán Postjix, Prejix
//    step 1. Prejix
//    step 2. Các phép toán còn lại
//    step 3. Gán các giá trị chi biến ở been trái dấu bằng
//    step 4. Tính Postjix

// ví dụ
// x = 1;
// y = 2;
// z = a++ - ++y +1;
// step 1 : ++y => y = 3
// step 2 : x = 1, y = 3 => 1 - 3 + 1 = -1
// step 3 : z = -1
// step 4 : x++ => x = 2