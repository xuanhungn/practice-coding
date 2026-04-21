// hàm Number (value) --> chuyển value sang số 
// --> Nếu không chuyển được trả về NaN
let str = "123";
let strNaN = "123a";

console.log(typeof str);
console.log(typeof strNaN);

let num = Number(str);
let numNaN = Number(strNaN);

console.log(num);
console.log(typeof num);

console.log(numNaN);
console.log(typeof numNaN);

// let so = Number(prompt("Mời nhập vào một số: "));
// console.log(so);

//Hàm isNaN (là  không phải số )
//nếu không phải là số sẽ cố gắng đổi nếu không đổi được nữa 
let a = "123a";
console.log(isNaN(a));

// true và false nếu được chuyển đổi từ number sang sẽ là số 1 và số 0
let tr = Number(true);
console.log(tr);
console.log(typeof tr);

let fol = Number(false);
console.log(fol);
console.log(typeof fol);
console.log(isNaN(fol));

/* hàm Number.isNaN Kiểm tra giá trị , hoặc biểu thức truyền
  vào phải chính xác truyền vào có phải là NaN hay không nếu
  chính xác là NaN thì trả về là true còn không thì trả về 
  false
  */

console.log(Number.isNaN(NaN));
console.log(Number.isNaN("abc" / "dsa"));