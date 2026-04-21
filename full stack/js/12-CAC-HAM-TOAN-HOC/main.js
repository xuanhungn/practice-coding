//1. Hàm `Math.sqrt()`
let a = Math.sqrt(4); //Lấy căn bậc hai của 4 gắn vào biến a
console.log(a);

//2. Hàm `Math.pow(base, exponent)` lấy lũy thừa chuyển vào hai đuôi số
let b = Math.pow(2, 3);
console.log(b);

//3. Hàm `Math.abs()` //  trị tuyệt đối  của một số
let c = Math.abs(-10);
console.log(c);

//4. Hàm `Math.cell()` và `Math.floor()` làm tròn lên làm tròn xuống
let d = Math.ceil(5.004); // làm tròn lên 
console.log(d);
let e = Math.floor(5.004); // làm tròn xuống
console.log(e);

//5.Hàm `Math.round()` , từ 0.5 làm tròn thành 1
let g = Math.round(7.49);
console.log(g);

//6. làm tròn x chữ số phần đơn vị bằng () 
let f = 3.11254;
let fRounded = f.toFixed(2);
let fRoundedd = Number(f.toFixed(2)); // chuyển đổi sang số

console.log(fRounded) // khi sử dụng toFixed từ number sẽ chuyển sang string(chuỗi)
console.log(typeof fRounded);
//cộng thử 
let congthu = fRounded + 5;
console.log(congthu);

let congthuu = fRoundedd + 5; // kết quả sau khi chuyển đổi chuỗi sang số
console.log(congthuu);

// 7. Hàm `Math.min()` và Hàm `Math.max`
let so1 = 3;
let so2 = 9;
let so3 = 4;

let minValue = Math.min(so1, so2, so3);
let maxValue = Math.max(so1, so2, so3);

console.log("Số nhỏ nhất là: " + minValue)
console.log("Số lớn nhất là: " + maxValue)