import random
import time
import timeit
matrix_1=[]
for i in range(512) :
  col=[]
  for j in range(512) :
    col.append(random.randint(0,1900000))
  matrix_1.append(col)  
  
matrix_2=[]
for a in range(512) :
  colm=[]
  for b in range(512) :
    colm.append(random.randint(0,1900000))
  matrix_2.append(colm)    




matrix_3=[]
for c in range(512):
  df=[]
  for m in range(512):
    df.append(0)
  matrix_3.append(df)

starttime=timeit.default_timer()

for d in range(512):
  for e in range(512):
    for f in range(512):
      matrix_3[d][e] += matrix_1[d][f]*matrix_2[f][e]

print(timeit.default_timer()-starttime)


