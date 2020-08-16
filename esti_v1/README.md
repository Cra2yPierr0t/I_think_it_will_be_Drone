# 位置推定

### 目的
素朴な実装で加速度センサから一直線上の位置推定をする

### やること
$\Delta t$が何秒か調べる
$\Delta t$ : HighとLowを読み出すのに掛かる時間

i2cの連続読み出しを調べる
-> (Masterが)NACKの替わりにACKを送信で次のデータが出力される。完成


* esti_core.sv  : 推定本体
* esti_top.sv   : 推定結果を見易くする
* /io           : i2c入出力 専用仕様

### 数式

* x(t)          : 位置
* v(t)          : 速度
* a(t)          : 加速度

* b(t)          : センサ出力

<img src="https://latex.codecogs.com/gif.latex?x(t&plus;\Delta&space;t)=x(t)&plus;\cfrac{1}{2}a(t)\Delta&space;t^2&plus;v(t)\Delta&space;t" />

<img src="https://latex.codecogs.com/gif.latex?x(t&plus;\Delta&space;t)=x(t)&plus;\cfrac{1}{2}\cdot\cfrac{b(t)}{2^{13}}g\Delta&space;t^2&plus;v(t)\Delta&space;t">

<img src="https://latex.codecogs.com/gif.latex?\cfrac{2^{13}}{g\Delta&space;t^2}x(t&plus;\Delta&space;t)=\cfrac{2^{13}}{g\Delta&space;t^2}x(t)&plus;\cfrac{1}{2}b(t)&plus;\cfrac{2^{13}}{g\Delta&space;t}v(t)">

<img src="https://latex.codecogs.com/gif.latex?y(t)=\cfrac{2^{13}}{g\Delta&space;t^2}x(t)">
とおいて
<img src="https://latex.codecogs.com/gif.latex?y(t&plus;\Delta&space;t)=y(t)&plus;\cfrac{1}{2}b(t)&plus;\cfrac{2^{13}}{g\Delta&space;t}v(t)">

また
<img src="https://latex.codecogs.com/gif.latex?v(t&plus;\Delta&space;t)=v(t)&plus;a(t)\Delta&space;t">

<img src="https://latex.codecogs.com/gif.latex?v(t&plus;\Delta&space;t)=v(t)&plus;\cfrac{g}{2^{13}}b(t)\Delta&space;t">

<img src="https://latex.codecogs.com/gif.latex?\cfrac{2^{13}}{g\Delta&space;t}v(t&plus;\Delta&space;t)=\cfrac{2^{13}}{g\Delta&space;t}v(t)&plus;b(t)">

<img src="https://latex.codecogs.com/gif.latex?w(t)=\cfrac{2^{13}}{g\Delta&space;t}v(t)">
とおいて
<img src="https://latex.codecogs.com/gif.latex?w(t&plus;\Delta&space;t)=w(t)&plus;b(t)">
以上より
<img src="https://latex.codecogs.com/gif.latex?y(t&plus;\Delta&space;t)=y(t)&plus;\cfrac{1}{2}b(t)&plus;w(t)">

<img src="https://latex.codecogs.com/gif.latex?w(t&plus;\Delta&space;t)=w(t)&plus;b(t)">
