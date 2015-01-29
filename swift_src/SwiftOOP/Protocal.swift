//
//  Protocal.swift
//  SwiftOOP
//
//  Created by Hope6537 on 15-1-27.
//  Copyright (c) 2015年 Hope6537. All rights reserved.
//

import Foundation

//Protocal即协议 就是所谓的Java和C#中的接口 即interface
//标准格式的协议可以被类，结构体和枚举遵循。
//类特定协议格式 前面加objc注解
@objc protocol Villa{
    //描述属性必须用var
    //实现时候必须和定义的名称一致
    //可以是类型属性，也可以是实例属性
    var floors : Int{get};
    var style : String{get};
    func openGate()->String;
    func openAirCondition()->Bool;
    //这个字段代表的是这个属性可以被选择性的实现
    optional func hasDogHouse()->Bool;
    //协议中的构造器
    init(weapon:String)
    //需要在协议中使用可失败构造器
    init?(hasWeapon:Bool);
}
//但是对于类特定协议格式的协议来说，只能够被类实现

//类特定协议格式 后面接class
protocol WorkShop : class{
    var desk:String{set get};
    var book : String{get};
    func program(code:String) ->Bool;
    func debug();
}
//普通格式
protocol GameRoom{
    var games:String{get}
}
//接口可以多重继承
protocol CombineRequirement:Villa,WorkShop{
    class var name : String{get};
    class func finish() -> Bool;
    
    
}

class OuterHorse :CombineRequirement{
    //协议中的构造器 实现的时候要添加required关键字
    required init(weapon:String){
        println("the weapon is \(weapon)");
    }
    //    同时也要实现可失败构造器
    required init?(hasWeapon:Bool){
        if hasWeapon == false{
            println("no weapon");
            return;
        }
        println("has weapon");
    }
    convenience init(){
        self.init(weapon:"minigun");
    }
    
    let floors = 4;
    var style:String {
        return "Europe";
    }
    func openGate()->String{
        return "auto Door";
    }
    func openAirCondition()->Bool{
        return true;
    }
    var desk : String{
        get{
            return "desk";
        }
        set{
            println("new desk \(newValue)");
        }
    }
    var book = "swift";
    
    func program(code:String) -> Bool{
        println("code is \(code)");
        return true;
    }
    
    func debug(){
        println("debug success");
    }
    
    class var name : String{
        return "outter";
    }
    class func finish()->Bool{
        return true;
    }
}

struct buildGameRoom : GameRoom{
    var games = "Battlefield";
}

func testProtocal(){
    var villa = OuterHorse(weapon: "m249");
    var base = OuterHorse(hasWeapon: true);
    
}