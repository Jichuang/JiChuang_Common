//
//  oop=.swift
//  SwiftOOP
//
//  Created by Hope6537 on 15-1-13.
//  Copyright (c) 2015�� Hope6537. All rights reserved.
//

import Foundation

class People{
    var name : String = "";
    var apperance : String = "";
    var dream : String = "";
    var reality : String = "";
    //���Թ۲���ģʽ
    var lover : People?{
        //���Ըı�ǰ����
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
        //���Ըı�󴥷�
        didSet(oldLover){
            if(oldLover != nil){
                println("\(self.name) has left the oldlover \(oldLover)");
            }
        }
    };
    //��������
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
    //������������� �����е�People����������
    class var plannet : String{
        //ͬ������дset��get
        get{
            return "����";
        }
        set{
     
        }
    }
    class var staticParam : String{
        return "��̬����";
    }
    class func staticFunc(){
        println("��̬����");
        println(staticParam);
    }
}

var oldCoder = People();
println("Old Coder is Happy :\(oldCoder.isHappy)");
oldCoder.isHappy = true;
println("app : \(oldCoder.apperance)");
println(People.plannet);

//���Թ۲���֮ȫ�ֱ���
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

//�±귽��
class Assistant{
    var interviewees:[Int:String] = [:];
    var name : String = "";
    //ʹ��subscript�ؼ���
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
    //ǰ�����final���ɷ�ֹ����д
    class func staticMethods(){
        println("yes");
    }
}
var myAssistant = Assistant();
myAssistant.name = "assistant";
//ʹ�������±�ĸ�ʽֱ�ӽ��и�ֵ ������Ҫ�������飬�������ֵ�
myAssistant[2] = "name1";
myAssistant[32] = "name2";
//ͬ���ģ��±�Ҳ���Զ��ֵ 
//ע��ʹ��!�����
println(myAssistant[2]!);
println(myAssistant[32]!);
println(myAssistant[2,31]!);
//��ļ̳з�ʽ
class Assistant_Son:Assistant{
    override class func staticMethods(){
        println("override");
    }
}
Assistant_Son.staticMethods();

