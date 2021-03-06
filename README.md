## 13.   CrackMe

В исходной программе генерация ключа происходит по следующему алгоритму. Сначала, строка посимвольно проверяется - если всретилась буква нижнего регистра, то переводим её в верхний регистр (отнимая 0x20 от её кода), верхний регистр - не трогаем, иной символ - прервать проверку, и сообщить о неудачной регистрации (символов строки, которые влияют на генерацию ключа - первые 10). После успешного перевода строки сумма её символов складывается по модулю 2 с константой **0x5678** - первое значение (в регистре EAX). Серийный ключ (как число в десятичной системе) складывается с константой **0x1234** - в регистр EBX. На основании сравнения этих регистров происходит либо успешная активация, либо неудача. 

```assembly
# Часть с проверкой

cmp   eax,0
je    crackme.4011E6
push  crackme.40218E
call  <crackme.sub_40137E>
push  eax
push  crackme.40217E
call  <crackme.sub_4013D8>
add   esp,4
pop   eax
cmp   eax,ebx                 # Здесь сравнение двух регистров, EAX - из имени EBX - из ключа
je    crackme.40124C          # Если ZF поднят, то прыгаем 0x0040124C
call  <crackme.sub_401362>    # Эта функция сообщит о неудаче
jmp   crackme.4011E6            
call  <crackme.sub_40134D>    # А эта функция покажет окно об успешной регистрации (0x0040124C)
jmp   crackme.4011E6        

```



Генерация ключа не составляет особых усилий, так как `0x1234 + name + 0x5678 = 0x1234 + key + 0x1234 = 0 + key = key`, в силу коммутативности и ассоциативности опреации сложения по модулю 2. 

Перевод строки в верхний регистр производится так 
```assembly
mov esi,dword ptr ss:[esp+4]
push esi
mov al,byte ptr ds:[esi]
test al,al
je crackme.40139C
cmp al,41
jb crackme.4013AC
cmp al,5A
jae crackme.401394
inc esi
jmp crackme.401383
call <crackme.sub_4013D2>
inc esi
jmp crackme.401383
pop esi
call <crackme.sub_4013C2>
xor edi,5678
mov eax,edi

```

Серийный ключ представляет собой некоторую строку ниже превращает её в число по основанию 16 (умножая на 0xA старший разряд и добавляя следующий пока символы не кончатся)

```assembly
xor eax,eax
xor edi,edi
xor ebx,ebx
mov esi,dword ptr ss:[esp+4]
mov al,A
mov bl,byte ptr ds:[esi]
test bl,bl
je crackme.4013F5
sub bl,30
imul edi,eax
add edi,ebx
inc esi
jmp crackme.4013E2
xor edi,1234
mov ebx,edi
```
