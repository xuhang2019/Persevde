
// ISP 接口隔离示例

class Bird {
   public:
        virtual void eat() = 0;
        virtual void breathe() = 0;
        virtual void fly() = 0;
};

    /*
        把Bird类 再拆分成 
        Lifeform
        Flyable
        这样对于不能飞的鸟，也可以继承这几个接口
    */

class Pigeon : public Bird {
   public:
        virtual void eat() override{
            // ...
        }
};

class Penguin : public Bird{
    public:
        virtual void eat() override{
            // ...
        }
        virtual void fly() override{ // 问题是 企鹅不会飞，说明Bird这个基类设计的太大了，需要进一步隔离开。
            // ...
        }
};


// DIP 依赖倒转示例

class Account;

class Customer{
    public:
        void setAccount(Account *account){ // customer 依赖 account
            this->customerAccount = account;
        }
    private:
        Account *customerAccount;
};

class Account{
    public:
        void setOwner(Customer *customer){ // account依赖customer
            this->owner = customer;
        }
    private:
        Customer *owner;

};


    // 一个较好的做法是去定义一个Owner接口，使得 account类不再去依赖Customer类。