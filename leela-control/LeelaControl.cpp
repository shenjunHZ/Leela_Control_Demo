﻿// LeelaControl.cpp: 定义应用程序的入口点。
/* 
* Copyright (C) jun shen
*/
#include "LeelaControl.hpp"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    app.setApplicationName("Leela-Control");
    constexpr int LEELA_CONTROL_VERSION = 1.0;
    app.setApplicationVersion(QString("V: ").arg(LEELA_CONTROL_VERSION));

    boost::program_options::variables_map cmdParams;
    helps::parseProgramOptions(argc, argv, cmdParams);

    try
    {
        configurations::AppConfiguration configParams =
            configurations::loadFromIniFile(cmdParams["config-file"].as<std::string>());
        const configurations::AppAddresses addresses = helps::getAppAddresses(configParams);

        std::cout << "Info: " << "Leela Control App Start up." << std::endl;
        applications::AppInstance appInstance(configParams, addresses);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << boost::diagnostic_information(e) << std::endl;
        return EXIT_FAILURE;
    }

	return app.exec();
}
