//
//  oop=.swift
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

