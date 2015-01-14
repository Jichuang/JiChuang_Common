//  Created by Hope6537 on 15-1-11.
//  Copyright (c) 2015�� Hope6537. All rights reserved.
//

import Foundation

var char1:String = "Hope6537";
var int1:Int = 123;
var boolean1 =  char1.hasPrefix("Hope");
var boolean2 = char1.hasSuffix("6537");
println("\(boolean1&&boolean2)");
//�ؼ�����
let responseData = (
    statusCode : 404,
    statusMsg : "Not Found"
);
println("\(responseData.statusCode)");
let possibleNumber = "123";
let convertedNumber =  possibleNumber.toInt();

//��ѡ����
if(convertedNumber != nil){
    println("\(convertedNumber) , has Value is \(convertedNumber!)")
}

//��ʽ���
let str1 :String! = "����ʽ���";
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

//���鴴���ͳ�ʼ��
var someInts = [Int]();
someInts.append(3);
//�������
someInts = [];
var someInt2 = [Int]();
someInt2 = [Int](count:3,repeatedValue:2);
someInts = someInts + someInt2;
//Key-Value �� HashMap
var emptyMap = [Int:String]();
//��ո�map
emptyMap = [:];
var games : [String:String] = ["game1":"value1","game2":"value2" ,"game3":"value3","game4":"value4" ];
//�������ӷ�ʽ �����key����ֵ ��ô��Ϊ����
games["game1"] = "change1";
//�᷵��ԭ����game1����Ӧ��ֵ
var res = games.updateValue("change2", forKey: "game1");
//�᷵��nil
var res2 = games.updateValue("change3", forKey: "game65535");
for(key,value) in games{
    //����ʹ���ַ���ƴ�ӵķ�ʽ������̫���ˣ��������java����Ա�ı�̷�ʽ
    println(key + ":" + value);
}
//�ṹ��
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
//����ʹ��RawValue����ȡֵ ʹ��HashValue����ȡö��key��index
println(Planet.Jupiter.hashValue);

//
//  �����������ϰ
//
//  Created by Hope6537 on 15-1-11.
//  Copyright (c) 2015�� Hope6537. All rights reserved.
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
//�޶���ʽ
for num in 0..<2{
    println(vales[num]);
}

for (var i = 0 ; i < vales.count ; i++){
    println("classic" + vales[i]);
}


//case��ֵ�󶨺�����ֵ��
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
//�������ⲿ������
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

//����������� Ĭ�ϲ������������ӽ��� ��Ȼ�����
//��������������Ĭ�ϰ汾��ô�죿
println(createByDefault(name: "sadasda" , isMale : true));

//�޸��β����ı�ʵ��
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

//ͨ��Ԫ������ɶ������ֵ������
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

//�������͵ĳ����ͱ��� ���� fun1�͵ȼ�������ķ����ˣ����������˸�����
var func1 : (Dictionary<String,String> -> (Int,Int)) = returnMultiValues;
//������Ϊ����
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
//������Ϊ����ֵ
func chooseReturnFunction(type : String) -> (String)->Bool{
    var returnFunc = get;
    if(type == "save"){
        returnFunc = save;
    }
    return returnFunc;
}
var str233 = "save";
let func2 = chooseReturnFunction(str233);
//��ʽ�ﻯ��ʽ
func curriedOnFunc1(x:Int) -> (Int->Int->Int){
    func curriedOnFunc2(y:Int) -> (Int->Int){
        func curriedOnFunc3(z:Int) ->(Int){
            return x+y+z;
        }
        return curriedOnFunc3;
    }
    return curriedOnFunc2;
}
//��ʽ���ﻯ��ʽ
func curriedInFunc(x:Int)(y:Int)(z:Int) -> Int{
    return x+y+z;
}

//���庯��
func sort(array:[Int], compareFunc:(Int,Int)->Bool) -> [Int]{
    return array;
}

func compareFunc1(i1:Int,i2:Int)->Bool{
    return i1 < i2;
}
var array = [1,2,3,5,6];
//����д��
var sortNumbers = sort(array,compareFunc1);
//�հ�д��1
var sortNumbers1 = sort(array,{i1,i2 in return i1<i2});
//�հ�д��2
var sortNumbers2 = sort(array,{i1,i2 in i1<i2});
//�հ�д��3
var sortNumbers3 = sort(array,{$0<$1});
//�հ�д��4 ����е��ը
var sortNumbers4 = sort(array,<);
//β�հ�д��
var sortNumbers5 = sort(array){
    (i1:Int,i2:Int) -> Bool
    in return i1 < i2;
}

