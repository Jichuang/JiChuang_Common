//
//  ExtensionSwift.swift
//  SwiftOOP
//
//  Created by Hope6537 on 15-1-27.
//  Copyright (c) 2015年 Hope6537. All rights reserved.
//

import Foundation

extension Double {
    
    static var name = "extension Double";
    static var factor : Double {
        return 12_500_000_000_000
    }
    var CHY : Double {
        return self / Double.factor;
    }
    var zeros : Int{
        var str = "\(self)";
        return str.lengthOfBytesUsingEncoding(NSUTF8StringEncoding) - 3;
    }
    func toString()->String{
        return Double.name;
    }
    static func getClassName()->String{
        return "\(name):\(self)"
    }
    
}

func testExtension(){
    var money : Double = 100_000_000_000_000;
    println("now \(money)");
    println("chy \(money.CHY)");
    println("now is \(money.toString())");
    println("has zero \(money.zeros)");
    println(Double.getClassName());
}