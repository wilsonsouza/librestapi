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
#include <restapi_settings_impl.hpp>
#include <restapi_resource_impl.hpp>
//--------------------------------------------------------------------------------------------//
namespace restapi
{
   class service_impl : public restbed::Service
   {
   public:
      using pointer = std::shared_ptr<service_impl>;
      using pointer_const = pointer const;
   public:
      static restapi::service_impl * m_service_handler;
      static const int m_port = 0x1f90;
   protected:
      resource_impl::stack_pointer m_resource_stacker =
         resource_impl::stack_pointer( new std::vector<resource_impl::pointer>( ) );
      settings_impl::pointer m_settings = settings_impl::pointer( new restapi::settings_impl( ) );
   public:
      service_impl( ) = default;
      service_impl( std::uint16_t const port ) : restbed::Service( )
      {
         m_settings->set_port( ( port == 0 ? service_impl::m_port : port ) );
      }
      virtual void push_back( std::shared_ptr<resource_impl> const & resource_class );
      virtual void start( settings_impl::pointer const & settings_ptr );
      virtual void set_settings( restapi::settings_impl::pointer const & ptr );
      virtual restapi::settings_impl::pointer_const & get_settings( void );
      virtual restapi::resource_impl::stack_pointer get_resources_stacker( );
      virtual void stop( ) = 0;
      /* static methods */
      static restapi::service_impl * get_service_handler( );
   };
}