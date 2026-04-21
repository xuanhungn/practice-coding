//bmi
let chieuCao = Number(prompt("Nhập chiều cao: "))
let canNang = Number(prompt("Nhập cân nặng: "))

let bmi = canNang / (chieuCao ^ 2);
console.log("BMI của bạn là =" + bmi);

if (bmi < 15) {
    console.log("Thân xác quá gầy");
} else if (bmi >= 15 && bmi < 16) {
    console.log("Thân hình gầy");
} else if (bmi >= 16 && bmi < 18.5) {
    console.log("Thân hình hơi gầy");
} else if (bmi >= 18.5 && bmi < 25) {
    console.log("Thân hình bình thường");
} else if (bmi >= 25 && bmi < 30) {
    console.log("Thân hình gầy");
} else if (bmi >= 30 && bmi < 35) {
    console.log("Thân hình béo");
} else {
    console.log("Thân hình béo");
}