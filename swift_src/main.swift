//  Created by Hope6537 on 15-1-11.
//  Copyright (c) 2015年 Hope6537. All rights reserved.
//

import Foundation

var char1:String = "Hope6537";
var int1:Int = 123;
var boolean1 =  char1.hasPrefix("Hope");
var boolean2 = char1.hasSuffix("6537");
println("\(boolean1&&boolean2)");
//关键集合
let responseData = (
    statusCode : 404,
    statusMsg : "Not Found"
);
println("\(responseData.statusCode)");
let possibleNumber = "123";
let convertedNumber =  possibleNumber.toInt();

//可选类型
if(convertedNumber != nil){
    println("\(convertedNumber) , has Value is \(convertedNumber!)")
}

//隐式解封
let str1 :String! = "隐藏式解封";
println(str1);

let age = -3;
//assert(age >= 0 , "age must > 0");

var teacherList : [String]  = ["t1","t2"];
println("arrayList size is \(teacherList.count)");
println("arrayList is empty?\(teacherList.isEmpty)");
teacherList.append("t3");
teacherList += ["t4","t5","t6"];
teacherList[0] = "teacher1";
teacherList[1...3] = ["te1","te2","te4"];
println(teacherList[0]);
teacherList.insert("test", atIndex : 5);
teacherList.removeAtIndex(2);
teacherList.removeLast();
for item in teacherList{
    println("teacherList element has \(item)");
}
for(index,value) in enumerate(teacherList){
    println("\(index) is  \(value) " );
}
for(var (index,value)) in enumerate(teacherList){
    println("\(index) + \(value)");
}

//数组创建和初始化
var someInts = [Int]();
someInts.append(3);
//清空数组
someInts = [];
var someInt2 = [Int]();
someInt2 = [Int](count:3,repeatedValue:2);
someInts = someInts + someInt2;
//Key-Value 的 HashMap
var emptyMap = [Int:String]();
//清空该map
emptyMap = [:];
var games : [String:String] = ["game1":"value1","game2":"value2" ,"game3":"value3","game4":"value4" ];
//新奇的添加方式 如果该key下有值 那么则为覆盖
games["game1"] = "change1";
//会返回原来的game1所对应的值
var res = games.updateValue("change2", forKey: "game1");
//会返回nil
var res2 = games.updateValue("change3", forKey: "game65535");
for(key,value) in games{
    //可以使用字符串拼接的方式啊～！太棒了，这才是我java程序员的编程方式
    println(key + ":" + value);
}
//结构体
struct Sword{
    var width : Float
    let name : String
    func description(){
        println("sword name is \(name) width is  \(width)");
    }
}
var sword : Sword = Sword( width: 1.2, name: "Log");
sword.description();

enum Planet : Int{
    case Mercury = 1  , Venus , Earth , Mars , Jupiter , Saturn , Uranus ,Neptune;
}
//必须使用RawValue来获取值 使用HashValue来获取枚举key的index
println(Planet.Jupiter.hashValue);

//
//  运算符重载练习
//
//  Created by Hope6537 on 15-1-11.
//  Copyright (c) 2015年 Hope6537. All rights reserved.
//

import Foundation

struct MySword{
    var length : Double;
    var weigth : Double;
    var name : String;
    
    func toString(){
        println(
            "Sword name = \(name) , length = \(length) , weigth = \(weigth)"
        );
    }
}

func + (left:MySword,right:MySword)->MySword{
    return MySword(length: left.length + right.length, weigth: left.weigth + right.weigth , name: "big" + left.name + "&" +  right.name);
}
func - (left:MySword,right:MySword)->MySword{
    return MySword(length: left.length - right.length, weigth: left.weigth - right.weigth , name: "small" + left.name);
}
prefix func - (left : MySword ) -> MySword{
    return MySword(length:-(left.length), weigth:-(left.weigth), name:left.name);
}

postfix func++ (inout left: MySword) -> MySword{
    return MySword(length: left.length++, weigth: left.weigth++, name: left.name);
}

func == (left:MySword , right : MySword ) -> Bool{
    return left.weigth == right.weigth && left.length == right.length;
}

var test1 = MySword(length: 1.0, weigth: 1.0, name: "small Sword");
var test2 = MySword(length: 2.0, weigth: 1.2, name: "small Sword2");

var big = test1 + test2;
test1.toString();
test2.toString();
big.toString();
var test3 = big - test1;
test3.toString();

infix operator +-*= {associativity right precedence 140 assignment};
func +-*= (inout left : MySword , right : MySword ) -> MySword {
    left = MySword(length: left.length + right.length, weigth: left.weigth - right.weigth , name: left.name + "%%" + right.name);
    return left;
}
test3 +-*= test1;
test3.toString();

//for

var jsonObject = [
    "test1":"value1",
    "test2":"value2",
    "test3":"value3"
];

for item in jsonObject{
    println(item.0 + " " + item.1);
}
var vales = [String](jsonObject.values);
//限定方式
for num in 0..<2{
    println(vales[num]);
}

for (var i = 0 ; i < vales.count ; i++){
    println("classic" + vales[i]);
}


//case的值绑定和条件值绑定
var enemyPosition = (54,54);

switch enemyPosition {
case let (x,55):
    println("case1");
case let (x,y) where x == y:
    println("case2");
case let (x,y) where x > 30 && x<45 :
    println("case3");
default :
    println("default");
}
//函数的外部参数名
func create(v1 value1 : String , v2 value2 : String){
    println(value2 + value1);
}

func createByParamToken(#value1 : String , #value2 : String){
    println(value1 + value2);
}
println(create(v1:"aaa",v2:"bbb"));
println(createByParamToken(value1: "dasd", value2: "dwqdqw"));

func createByDefault(#name : String , isMale : Bool = true){
    if(isMale){
        println(name +  "male");
    }else{
        println(name + "female");
    }
}

func createByDefault(#name : String){
    println(name +  "male");
}

//如果出现重载 默认参数必须带着添加进入 不然会混淆
//但是如果我想调用默认版本怎么办？
println(createByDefault(name: "sadasda" , isMale : true));

//修改形参来改变实参
func swap(inout a : Int , inout b : Int){
    let temp = a;
    a = b;
    b = temp;
}
var aaaa = 1;
var bbbb = 2;
swap(&aaaa, &bbbb);
println(aaaa);
println(bbbb);

//通过元组来达成多个返回值的特性
func returnMultiValues (kids : Dictionary<String,String>) ->  (boys : Int , girls : Int){
    var boys  = 0;
    var girls = 0;
    for people in kids{
        switch people.0{
            case "boys":
                boys++;
            case "girls":
                girls++;
            default:
                break;
        }
    }
    return (boys,girls);
}

var kids : Dictionary<String,String> = ["james":"boys","kenny":"girls"];
var(b,g) = returnMultiValues(kids);

//函数类型的常量和变量 这样 fun1就等价于上面的方法了，类似于起了个别名
var func1 : (Dictionary<String,String> -> (Int,Int)) = returnMultiValues;
//函数作为参数
func functionByParam(countFunc : (Dictionary<String,String> -> (Int,Int)) , kids : Dictionary<String,String>) -> (Int,Int){
    return countFunc(kids);
}
println(functionByParam(func1,kids));

func save(number : String) -> Bool{
    println("save money" + number);
    return true;
}
func get(number : String) -> Bool{
    println("get money" + number);
    return false;
}
//函数作为返回值
func chooseReturnFunction(type : String) -> (String)->Bool{
    var returnFunc = get;
    if(type == "save"){
        returnFunc = save;
    }
    return returnFunc;
}
var str233 = "save";
let func2 = chooseReturnFunction(str233);
//显式里化形式
func curriedOnFunc1(x:Int) -> (Int->Int->Int){
    func curriedOnFunc2(y:Int) -> (Int->Int){
        func curriedOnFunc3(z:Int) ->(Int){
            return x+y+z;
        }
        return curriedOnFunc3;
    }
    return curriedOnFunc2;
}
//隐式柯里化形式
func curriedInFunc(x:Int)(y:Int)(z:Int) -> Int{
    return x+y+z;
}

//定义函数
func sort(array:[Int], compareFunc:(Int,Int)->Bool) -> [Int]{
    return array;
}

func compareFunc1(i1:Int,i2:Int)->Bool{
    return i1 < i2;
}
var array = [1,2,3,5,6];
//经典写法
var sortNumbers = sort(array,compareFunc1);
//闭包写法1
var sortNumbers1 = sort(array,{i1,i2 in return i1<i2});
//闭包写法2
var sortNumbers2 = sort(array,{i1,i2 in i1<i2});
//闭包写法3
var sortNumbers3 = sort(array,{$0<$1});
//闭包写法4 这个有点刁炸
var sortNumbers4 = sort(array,<);
//尾闭包写法
var sortNumbers5 = sort(array){
    (i1:Int,i2:Int) -> Bool
    in return i1 < i2;
}

