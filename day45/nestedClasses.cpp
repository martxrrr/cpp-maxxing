#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdint>
#include <memory>
#include <algorithm>


class CanMessage{
    public:
    class Header{
        public:
        Header() = default;
        Header(uint32_t id, uint8_t dlc, bool is_extended, bool is_rtr)
            : arb_id_(id), dlc_(dlc), extended_frame_(is_extended), rtr_(is_rtr) {}
        
        uint32_t getArbId() const { return arb_id_;         }
        uint8_t getDlc()    const { return dlc_;            }
        bool isExtended()   const { return extended_frame_; }
        bool isRtr()        const { return rtr_;            }

        void setArbId(uint32_t id)  { srb_id_ = id;                }
        void setDlc(uint8_t dlc)    { dlc_ = (dlc <= 8) ? dlc : 8; }
        void setExtended(bool ext)  { extended_frame_ = ext;       }
        void setRtrt(bool rtr)      { rtr_ = rtr;                  }

        private:
        uint32_t arb_id_      =    0x000;
        uint8_t dlc_          =    0;
        bool extended_frame_  =    false;
        bool rtr_             =    false;
    };

    class Payload{
        public:
        Payload() {data_.fill(0x000); }

        void setByte(size_t index, uint8_t value) {
            if(index < 8) data_[index] = value;
        }

        uint8_t getByte(size_t index) const {
            return (index < 8) ? data_[index] : 0;
        }

        const std::array<uint8_t, 8>& raw() const { return data_; }


        private:
        std::array<uint8_t, 8> data_;
    };

    //PUBLIC INTERFACE
    CanMessage() = default;
    CanMessage(uint32_t id, uint8_t dlc) {
        header_.setArbId(id);
        header_.setDlc(dlc);
    }

    Header& header()                   { return header_;  }
    const Header& header()   const     { return header_;  }
    Payload& payload()                 { return payload_; }
    const Payload& payload() const     { return payload_; }

    void print() const {
        std::cout << "CAN Frame [ID=Ox]" << std::hex << header_.getArbId()
                  << std::dec << "DLC=" << static_cast<int>(header_.getDlc())
                  << "EXT=" << header_.isExtended()
                  <<"RTR=" << header.isRtr() << "] Data: ";
          
                  
        for (uint8_t i = 0; i < header_.getDlc(); i++) {
            std::cout << "0x" << std::hex
                      << static_cast<int>(payload_.getByte(i)) << " ";
        }

        std::cout << std::dec << "\n";
    }

    private:
    Header header_;
    Payload payload_;

};

int main(){

    std::cout << "CanMessage with Nested Header and Payload\n";
    CanMessage msg(0x1A3, 4);
    msg.payload().setByte(0, 0xDE);
    msg.payload().setByte(1, 0xAD);
    msg.payload().setByte(2, 0xBE);
    msg.payload().setByte(3, 0xEF);
    msg.print();


    return 0;
}

/*
A nested class is a class defined inside another class. The inner class logically belongs to the outer class and is
scoped within it

 a nested class can access the private and protected members of its enclosing class (given an
instance of the outer class). The outer class, however, has NO special access to the nested class's private
members. This asymmetry is important for encapsulation.

A local class is defined inside a function body. Its scope is limited to that function — it cannot be used outside.
Local classes cannot access the function's automatic (local) variables but can access static locals and global
variables. Use cases are rare; lambdas often replace them.
*/