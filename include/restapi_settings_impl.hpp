/*
*
*  librestapi c++11 Version 1.0
*
*
*  Created by Wilson.Souza
*  Copyright (C) 2017, WR DevInfo, All Rights Reserved.
*
*  Description:
*  Last update:
*
*  Dependence: boost::asio, catch, kashmir, openssl
*/
#pragma once
//--------------------------------------------------------------------------------------------//
#include <restbed>
//--------------------------------------------------------------------------------------------//
namespace restapi
{
   class settings_impl: public restbed::Settings
   {
   public:
      using pointer = std::shared_ptr<settings_impl>;
      using pointer_const = pointer const;
   public:
      settings_impl( void );
      virtual ~settings_impl( );
   };
}
//--------------------------------------------------------------------------------------------//