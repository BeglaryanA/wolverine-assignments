#include "FakeCPU.h"
#include <fstream>

void FakeCPU::get(std::string name)
{
    std::string line;
    this->file.open("text.txt");
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            this->cut(line);
        }
    }
    else
    {
        std::cout << "File is not open!!!" << std::endl;
    }
    file.close();
}

void FakeCPU::cut(std::string &rhs)
{
    std::string operation = "";
    std::string reg = "";
    std::string src = "";
    if (rhs.find(':') != -1)
    {
        rhs.erase(rhs.begin() + rhs.find(':'));
        label[rhs] = this->file.tellg();
        return;
    }
    if (rhs.find(',') != -1)
    {
        rhs.erase(rhs.begin() + (rhs.find(',')));
    }
    int space = 0;
    for (int i = 0; i < rhs.size(); ++i)
    {
        if (rhs[i] == ' ')
        {
            ++space;
        }
    }
    if (space == 1)
    {
        for (int i = 0; i < rhs.size(); ++i)
        {
            if (rhs[i] == ' ')
            {
                operation += rhs.substr(0, i);
                rhs.erase(rhs.begin(), rhs.begin() + i + 1);
            }
        }
        reg += rhs;
    }
    if (space == 2)
    {
        for (int i = 0; i < rhs.size(); ++i)
        {
            if (rhs[i] == ' ')
            {
                operation += rhs.substr(0, i);
                rhs.erase(rhs.begin(), rhs.begin() + i + 1);
                reg += rhs.substr(0, rhs.find(' '));
                rhs.erase(rhs.begin(), rhs.begin() + rhs.find(' ') + 1);
            }
        }
        src += rhs;
    }
    (this->*Func[operation])(reg, src);
}
/// check functions
bool FakeCPU::check_reg(std::string &str)
{
    for (int i = 0; i < reg.size(); ++i)
    {
        if (reg.find(str) == reg.end())
        {
            return false;
        }
    }
    return true;
}

bool FakeCPU::is_number(std::string &str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (!(str[i] <= '9' && str[i] >= '0'))
        {
            return false;
        }
    }
    return true;
}
//
void FakeCPU::mov(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) = stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) = *(reg[src]);
            return;
        }
    }
    throw std::invalid_argument("register not found");
}
// arichmetich
void FakeCPU::add(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) += stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) += *(reg[src]);
            return;
        }
    }
    throw std::invalid_argument("register not found");
}

void FakeCPU::mul(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) *= stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) *= *(reg[src]);
            return;
        }
    }
    throw std::invalid_argument("register not found");
}

void FakeCPU::div(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) /= stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) /= *(reg[src]);
            return;
        }
    }
    throw std::invalid_argument("register not found");
}

void FakeCPU::sub(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) -= stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) -= *(reg[src]);
            return;
        }
    }
    throw std::invalid_argument("register not found");
}

// logical
void FakeCPU::_and(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) &= stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) &= *(reg[src]);
            return;
        }
    }
    throw std::logic_error("Error");
}

void FakeCPU::_or(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) |= stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) |= *(reg[src]);
            return;
        }
    }
    throw std::logic_error("Error");
}

void FakeCPU::_xor(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        if ((!check_reg(src)) && is_number(src))
        {
            *(reg[dest]) ^= stoi(src);
            return;
        }
        if (check_reg(src))
        {
            *(reg[dest]) ^= *(reg[src]);
            return;
        }
    }
    throw std::logic_error("Error");
}

void FakeCPU::_not(std::string &dest, std::string &src)
{
    if (check_reg(dest))
    {
        *(reg[dest]) = (~*(reg[dest]));
    }
}
// jumps
void FakeCPU::jumps_impl(std::string &dest, std::string &src)
{
    if (is_number(src) && (src != "0"))
    {
        if (*(reg[dest]) == (stoi(src)))
        {
            Jumps["je"] = true;
            Jumps["jle"] = true;
            Jumps["jge"] = true;
            Jumps["jnz"] = true;
            Jumps["jz"] = false;
            Jumps["jne"] = false;
            Jumps["jl"] = false;
            Jumps["jg"] = false;
            return;
        }
        else if (*(reg[dest]) < (stoi(src)))
        {
            Jumps["jl"] = true;
            Jumps["jle"] = true;
            Jumps["jnz"] = true;
            Jumps["jne"] = true;
            Jumps["je"] = false;
            Jumps["jge"] = false;
            Jumps["jz"] = false;
            Jumps["jg"] = false;
            return;
        }
        else if (*(reg[dest]) > (stoi(src)))
        {
            Jumps["jg"] = true;
            Jumps["jge"] = true;
            Jumps["jnz"] = true;
            Jumps["jne"] = true;
            Jumps["je"] = false;
            Jumps["jle"] = false;
            Jumps["jz"] = false;
            Jumps["jl"] = false;
            return;
        }
    }
    else if (src == "0")
    {
        Jumps["jz"] = true;
        return;
    }
    if (check_reg(src))
    {
        if (*(reg[dest]) == *(reg[src]))
        {
            Jumps["je"] = true;
            Jumps["jle"] = true;
            Jumps["jge"] = true;
            Jumps["jnz"] = true;
            Jumps["je"] = false;
            Jumps["jle"] = false;
            Jumps["jge"] = false;
            Jumps["jz"] = false;
            Jumps["jne"] = false;
            Jumps["jl"] = false;
            Jumps["jg"] = false;
            Jumps["jnz"] = false;
            return;
        }
        else if (*(reg[dest]) < *(reg[src]))
        {
            Jumps["jl"] = true;
            Jumps["jle"] = true;
            Jumps["jnz"] = true;
            Jumps["jne"] = true;
            Jumps["je"] = false;
            Jumps["jge"] = false;
            Jumps["jz"] = false;
            Jumps["jg"] = false;
            return;
        }
        else if (*(reg[dest]) > *(reg[src]))
        {
            Jumps["jg"] = true;
            Jumps["jge"] = true;
            Jumps["jnz"] = true;
            Jumps["jne"] = true;
            Jumps["je"] = false;
            Jumps["jle"] = false;
            Jumps["jz"] = false;
            Jumps["jl"] = false;
            Jumps["jnz"] = false;
            return;
        }
    }
    else if (*(reg[src]) == 0)
    {
        Jumps["jz"] = true;
        return;
    }
}

void FakeCPU::jmp(std::string &dest, std::string &src)
{
    this->file.seekg(this->label[dest]);
}

void FakeCPU::cmp(std::string &dest, std::string &src)
{
    if ((!check_reg(dest)) && is_number(dest) && check_reg(src))
    {
        jumps_impl(src, dest);
    }
    else if (check_reg(dest) && (is_number(src) || check_reg(src)))
    {
        jumps_impl(dest, src);
    }
}

void FakeCPU::jl(std::string &dest, std::string &src)
{
    if (Jumps["jl"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::jle(std::string &dest, std::string &src)
{
    if (Jumps["jle"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::jg(std::string &dest, std::string &src)
{
    if (Jumps["jg"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::jge(std::string &dest, std::string &src)
{
    if (Jumps["jge"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::jne(std::string &dest, std::string &src)
{
    if (Jumps["jne"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::jz(std::string &dest, std::string &src)
{
    if (Jumps["jz"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::jnz(std::string &dest, std::string &src)
{
    if (Jumps["jnz"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::je(std::string &dest, std::string &src)
{
    if (Jumps["je"])
    {
        this->file.seekg(this->label[dest]);
    }
}

void FakeCPU::make()
{
    //Registers
    reg["r1"] = &r1;
    reg["r2"] = &r2;
    reg["r3"] = &r3;
    reg["r4"] = &r4;
    reg["r5"] = &r5;
    reg["r6"] = &r6;
    reg["r7"] = &r7;
    reg["r8"] = &r8;
    reg["r9"] = &r9;
    reg["r10"] = &r10;
    //Member functions
    Func["mov"] = &FakeCPU::mov;
    Func["add"] = &FakeCPU::add;
    Func["mul"] = &FakeCPU::mul;
    Func["sub"] = &FakeCPU::sub;
    Func["div"] = &FakeCPU::div;
    Func["and"] = &FakeCPU::_and;
    Func["or"] = &FakeCPU::_or;
    Func["xor"] = &FakeCPU::_xor;
    Func["not"] = &FakeCPU::_not;
    Func["jmp"] = &FakeCPU::jmp;
    Func["je"] = &FakeCPU::je;
    Func["jne"] = &FakeCPU::jne;
    Func["jl"] = &FakeCPU::jl;
    Func["jg"] = &FakeCPU::jg;
    Func["jle"] = &FakeCPU::jle;
    Func["jge"] = &FakeCPU::jge;
    Func["jz"] = &FakeCPU::jz;
    Func["jze"] = &FakeCPU::jnz;
    Func["cmp"] = &FakeCPU::cmp;
    //Jumps
    Jumps["je"] = false;
    Jumps["jle"] = false;
    Jumps["jge"] = false;
    Jumps["jz"] = false;
    Jumps["jne"] = false;
    Jumps["jl"] = false;
    Jumps["jg"] = false;
    Jumps["jnz"] = false;
}