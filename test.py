# def sum(n):
#     su = 0
#     while n>0:
#         su+=(n%10)
#         n = int(n/10)
#     return su
# def magic(n):
#     sm = sum(n)
#     if int(sm/10)>0 :
#         return magic(sm)
#     elif sm==1:
#         return 1
#     else :
#         return 0 
# def magicItr(n):
#     sm = n
#     while(1):
#         sm = sum(sm)
#         if int(sm/10)<=0 :
#             if sm==1:
#                 return 1
#             else:
#                 return 0
# l = int(input())
# r = int(input())
# for i in range(l,r+1):
#     if magic(i) : print(i)
#     # print(magicItr(i)) for iterative method.
