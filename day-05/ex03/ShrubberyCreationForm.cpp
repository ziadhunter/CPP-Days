/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:19:01 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/08 05:58:26 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", "unknown", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const  ShrubberyCreationForm& other)
{
    *this = other;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const  ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->set_attr(other.getName(), other.getTarget(),
                other.getIsSigned(), other.getSignGrade(), other.getExecGrade());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::exec() const
{
    const std::string treeLines[18] = {
        "           ,           ",
        "          / \\          ",
        "        .'   '.        ",
        "       /       \\       ",
        "      /.-.   .-.\\      ",
        "      `/  '.'   \\`     ",
        "     .'          '.    ",
        "    /.--.     .--.\\    ",
        "    `/   '. .'    \\`   ",
        "   .'      `       '.  ",
        "  /.---.       .----.\\ ",
        "  `/    `.   .'     \\` ",
        " .'       `.'        '.",
        "/,----,          ,----,\\",
        "`'-.__.;-,____,-;.__.-'",
        "         |||||         ",
        "         |||||         ",
        "         `\"\"\"`         "
    };
    std::ofstream file;
    std::string filename = this->getTarget() + "_shrubbery";

    file.open(filename.c_str());
    if (!file.is_open())
        return ;

    for (int i = 0; i < 18; i++)
        file << treeLines[i] << std::endl;

    file.close();
}