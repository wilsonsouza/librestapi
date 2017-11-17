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
#include <restapi_service_impl.hpp>
#include <restapi_resource_impl.hpp>
//--------------------------------------------------------------------------------------------//
using namespace restapi;
//--------------------------------------------------------------------------------------------//
restapi::service_impl * restapi::service_impl::m_service_handler = nullptr;
//--------------------------------------------------------------------------------------------//
void service_impl::push_back( std::shared_ptr<restapi::resource_impl> const & resource_class )
{
   this->m_resource_stacker->push_back( resource_class );
   this->publish( resource_class );
}
//--------------------------------------------------------------------------------------------//
void service_impl::start( settings_impl::pointer const & config_ptr )
{
   restapi::service_impl::m_service_handler = this;
   restbed::Service::start( config_ptr );
}
//--------------------------------------------------------------------------------------------//
void service_impl::set_settings( restapi::settings_impl::pointer const & ptr )
{
   if( m_settings != nullptr )
   {
      m_settings.swap( const_cast< restapi::settings_impl::pointer & >( ptr ) );
   }
}
//--------------------------------------------------------------------------------------------//
restapi::settings_impl::pointer const & service_impl::get_settings( void )
{
   return m_settings;
}
//--------------------------------------------------------------------------------------------//
restapi::service_impl * restapi::service_impl::get_service_handler( )
{
   return m_service_handler;
}
//--------------------------------------------------------------------------------------------//
restapi::resource_impl::stack_pointer restapi::service_impl::get_resources_stacker( )
{
   return m_resource_stacker;
}
//--------------------------------------------------------------------------------------------//