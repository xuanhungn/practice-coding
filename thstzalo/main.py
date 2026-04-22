import requests
import time

def lay_cau_noi_ngau_nhien():
    # Sử dụng một API miễn phí để lấy dữ liệu
    url = "https://dummyjson.com/quotes/random"
    
    try:
        # Gửi yêu cầu tải dữ liệu
        response = requests.get(url)
        
        # Kiểm tra xem yêu cầu có thành công không (mã 200 là OK)
        if response.status_code == 200:
            data = response.json()
            quote = data.get('quote', 'Không có nội dung')
            author = data.get('author', 'Khuyết danh')
            
            print("\n" + "="*50)
            print(f"💡 \"{quote}\"")
            print(f"{' ' * 20} - {author} -")
            print("="*50 + "\n")
        else:
            print("❌ Lỗi: Không thể tải dữ liệu từ máy chủ.")
            
    except requests.exceptions.RequestException as e:
        print(f"❌ Lỗi kết nối mạng: {e}")

if __name__ == "__main__":
    print("⏳ Đang tìm kiếm một câu nói hay cho bạn...")
    time.sleep(1) # Tạo hiệu ứng chờ 1 giây cho tự nhiên
    lay_cau_noi_ngau_nhien()