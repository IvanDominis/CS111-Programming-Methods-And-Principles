# HÀM CHUYỂN ĐỔI LÁ BÀI THÀNH ĐIỂM TƯƠNG ỨNG VỚI 52 LÁ
def changetopoint(card):
    if card[0]>='1' and card[0]<='9':
        check = int(card[0])-1
        point = 4*(check-1)
    else:
        if card[0]== 'T':   point = 32
        elif card[0]== 'J': point = 36
        elif card[0]== 'Q': point = 40
        elif card[0]== 'K': point = 44
        else: point = 48
    if card[1]  == 'N': point+=1
    elif card[1]== 'R': point+=2
    elif card[1]== 'B': point+=3
    else: point+=4
    return point
# HÀM TÍNH ĐIỂM THẮNG CỦA EVA VỚI ADAM
def Evapoint(adam,eva,n):
    p = []
    i = 0
    for i in range(n):
        j = 1
        point = 0
        for j in range(adam[i][0]):
            x,y = eva[i][j+1], adam[i][j+1]
            if x>y:
                point+=1
        p.append(point)
    return p
# THAO TÁC MỞ FILE TEXT VÀ ĐỌC FILE
f = open('CARD.txt', 'r')
with open('CARD.txt', 'r') as f:
    data = [s.strip() for s in f.readlines()]
# TÁCH THÀNH 2 MẢNG GỒM CÁC LÁ BÀI CỦA ADAM VÀ EVA VỚI N LẦN TƯƠNG ỨNG N LÁ
for i in range(len(data)):
    if(len(data[i])==2):
        data[i]= changetopoint(data[i])
    else:
        data[i]= int(data[i])
adam = []
eva = [] 
n ,i,m,l= int(data[0]),0, 1,0
for i in range(n):
    adam.append([])
    eva.append([])
    adam[i].append(data[m])
    eva[i].append(data[m])
    x = i+1
    m+=1 
    while x>0:
        adam[i].append(data[m])
        eva[i].append(data[m+i+1])
        x-=1
        m+=1
    m+=i+1
#print(adam,eva) 
# HÀM CHUYỂN VỀ MẢNG 1 CHIỀU 
def array1dimension(a,n):
    b= []
    for i in range(n):
        for j in range(a[i][0]):
            b.append(a[i][j+1])
    return b
# HÀM TÌM KIẾM LÁ BÀI LỚN HƠN GẦN NHẤT
def search(x,e):
    maxnear = []
    for i in range(len(e)):
        if e[i]> x:
            maxnear.append(e[i])
    if maxnear == []:
        return -1
    return min(maxnear)
# HÀM TÌM KIẾM VỊ TRÍ I, J CỦA 1 GIÁ TRỊ
def searchforij(x,eva,n):
    for i in range(n):
        for j in range(eva[i][0]):
            if x == eva[i][j+1]:
                return i,j+1
# HÀM ĐỔI GIÁ TRỊ CỦA 2 PHẦN TỬ CỦA MẢNG
def swap(x,y):
   return(y,x)
# SẮP BÀI CỦA EVA TỐI ƯU NHẤT ĐỂ THẮNG NHIỀU HƠN ADAM
e=array1dimension(eva,n)
for i in range(n):
    for j in range(adam[i][0]):
        d = search(adam[i][j+1],e)
        if d == eva[i][j+1]:
            e.remove(d)
            continue
        elif d>0:
            u,y =searchforij(d,eva,n)
            eva[i][j+1],eva[u][y]= swap(eva[i][j+1],eva[u][y])
        else:
            continue
        e.remove(d)
print(eva)
# GHI KẾT QUẢ VÀO FILE OUTPUT.txt
k=Evapoint(adam,eva,n)
with open('OUTPUT.txt', mode='w') as t:
    for i in range(len(k)):
        t.write(str(k[i])+'\n')
print(changetopoint("JR"))
