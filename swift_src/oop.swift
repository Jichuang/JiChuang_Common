//
//  main.swift
//  SwiftOOP
//
//  Created by Hope6537 on 15-1-13.
//  Copyright (c) 2015年 Hope6537. All rights reserved.
//

import Foundation

class People{
    var name : String = "";
    var apperance : String = "";
    var dream : String = "";
    var reality : String = "";
    //属性观察器模式
    var lover : People?{
        //属性改变前触发
        willSet(newLover){
            if(self.lover != nil){
                if(newLover != nil){
                    println("\(self.name) lover has changed to \(newLover)");
                }
            }
            else{
                if(newLover != nil){
                    println("\(self.name) has found first love  \(newLover)");
                }
            }
        }
        //属性改变后触发
        didSet(oldLover){
            if(oldLover != nil){
                println("\(self.name) has left the oldlover \(oldLover)");
            }
        }
    };
    //计算属性
    var isHappy : Bool{
        get{
            if(dream != "" && dream == reality || lover != nil || apperance == "handsome"){
                return true;
            }else{
                return false;
            }
        }
        set{
            if(newValue == true){
                apperance = "handsome";
            }else{
                apperance = "pool";
            }
        }
    }
    //这个是类型属性 被所有的People对象所共有
    class var plannet : String{
        //同样可以写set和get
        get{
            return "地球";
        }
        set{
     
        }
    }
    class var staticParam : String{
        return "静态变量";
    }
    class func staticFunc(){
        println("静态方法");
        println(staticParam);
    }
}

var oldCoder = People();
println("Old Coder is Happy :\(oldCoder.isHappy)");
oldCoder.isHappy = true;
println("app : \(oldCoder.apperance)");
println(People.plannet);

//属性观察器之全局变量
var salary :Int = 200{
    willSet(newValue){
        println("change the charge \(newValue)");
    }
    didSet(oldValue){
        if(salary >= (oldValue + 50)){
            println("amazing");
        }
    }
}
func showResult(){
    salary = 250;
}
showResult();
println(People.staticParam);
println(People.staticFunc());

//下标方法
class Assistant{
    var interviewees:[Int:String] = [:];
    var name : String = "";
    //使用subscript关键字
    subscript (number : Int) -> String?{
        get{
            return interviewees[number];
        }
        set{
            interviewees[number] = newValue;
        }
    }
    subscript (number:Int , door : Int) ->String?{
        get{
            println("to the door of \(door)");
            return interviewees[number];
        }
    }
    //前面加上final即可防止被重写
    class func staticMethods(){
        println("yes");
    }
}
var myAssistant = Assistant();
myAssistant.name = "assistant";
//使用类似下标的格式直接进行赋值 而不需要操作数组，或者是字典
myAssistant[2] = "name1";
myAssistant[32] = "name2";
//同样的，下标也可以多个值 
//注意使用!来解包
println(myAssistant[2]!);
println(myAssistant[32]!);
println(myAssistant[2,31]!);
//类的继承方式
class Assistant_Son:Assistant{
    override class func staticMethods(){
        println("override");
    }
}
Assistant_Son.staticMethods();
//构造类的实例
class Buddna {
    var name : String;
    //这是普通的指定构造器
    init(theFirstMethod name:String){
        println("first");
        self.name = name;
    }
    //构造器可以重载
    init(theSecondMethod name:String){
        println("second");
        self.name = name;
    }
    //便利构造器 调用其他构造器的方法
    convenience init (){
        println("convenience");
        self.init(theSecondMethod:"theFirst");
    }
    //可失败构造器，用于不符合条件时返回null对象
    init?(name : String){
        self.name = name;
        //返回失败必须在最后
        if(name == "failed"){
            return nil;
        }
    }
    deinit{
        println("destroy");
    }
}
//调用构造方法的同时 我们对这个对象进行了创建 并具有一个强引用
var buddna1:Buddna? = Buddna(theFirstMethod: "first");
var buddna2 = Buddna(theSecondMethod: "second");
//释放资源 调用destory方法
//在1中可以直接赋值为nil 因为在定义的时候我们使用了可选类型
buddna1 = nil;
//否则就像2一样 只能由Buddna类型来装载
buddna2 = Buddna(theFirstMethod: "123");
//指定构造器中的链式调用父类构造器
class base1 {
    var name1 : String;
    init(){
        self.name1 = "test";
        println("base init \(name1)" );
    }
}
class base2 : base1{
    var name2 : String;
    override init(){
        self.name2 = "base2";
        println("base2 name \(name2)");
        //显示的调用superinit之后彩才可以使父类的值
        super.init();
        self.name1 = "name1";
    }
}
/*
output:
base2 name base2
base init test
*/
var testBase = base2();
//要记住的是，在Swift中除了Class之外，其他的全都是值类型
//值类型有个方法叫做变质方法。用于修改当前的实例，而不是通过当前实例的基础上来修改属性

struct WarCraft {
    var sence : String;
    var money : Int;
    mutating func jumpToSence(sence:String){
         //在这里直接生产一个新的实例
        self = WarCraft(sence: "new Sence", money: 123);
    }
    func toString(){
        println("sence " + self.sence);
        println("money  \(self.money)");
    }
}

func testMutiating(){
    var myWarCraft = WarCraft(sence: "sence1", money: 1100);
    myWarCraft.toString();
    //after
    myWarCraft.jumpToSence("die");
    myWarCraft.toString();
}
testMutiating();
//闭环的强引用，即发生内存泄露的元凶
class Male{
    let name : String;
//   使用强引用
//   var girl : Female?;
//   使用弱引用
//    weak var girl : Female?;
//    使用无主引用 即主人死亡之后 该实例自动销毁 或者说计数－1
//    即girl死后 boy也殉情了
    unowned var girl : Female;
//  在无主引用中时，构造器必须给定无主引用变量的值
//    init(name : String){
//        self.name = name;
//    }
    init(name : String , girl : Female){
        self.name = name;
        self.girl = girl;
    }
    deinit{
        println("die male");
    }
}

class Female {
    let name : String;
    weak var boy : Male?;
    init (name : String){
        self.name = name;
    }
    deinit{
        println("die fe");
    }
}
func deadLock(){
    //出现了内存泄露
    var woman : Female? = Female(name:"female");
    var man : Male? = Male(name: "male",girl:woman!);
    //在无主引用中要使用！来进行强制解封来使用里面的值
    //man!.girl =  woman;

    woman!.boy = man;
    println("deinit");
    //无主引用中 girl死了boy也会跟着死
    //man = nil;
    woman = nil;
    println("finish");
}
deadLock();
