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
#include <restapi_resource_impl.hpp>
//--------------------------------------------------------------------------------------------//
using namespace restapi;
//--------------------------------------------------------------------------------------------//
resource_impl::resource_impl( std::string const & resource_name ) :
   restbed::Resource( ),
   m_url( resource_name )
{
   this->set_path( resource_name );
}
//--------------------------------------------------------------------------------------------//
void resource_impl::bind( std::string const & method_name,
                          std::function<void( const session_impl::pointer )> const & bind_func,
                          rules_map const & rules )
{
   /* assign method */
   m_method_bind.assign( method_name );
   /**/
   if( rules.empty( ) )
   {
      this->set_method_handler( method_name, bind_func );
   }
   else
   {
      this->set_method_handler( method_name, rules, bind_func );
   }
}
//--------------------------------------------------------------------------------------------//
void resource_impl::on_prepare_method_router( )
{
}
//--------------------------------------------------------------------------------------------//
void resource_impl::start( )
{
   this->on_prepare_method_router( );
}
//--------------------------------------------------------------------------------------------//
std::string const & resource_impl::get_url( )
{
   return this->m_url;
}
//--------------------------------------------------------------------------------------------//
std::string const & resource_impl::get_method_bind( )
{
   return m_method_bind;
}
//--------------------------------------------------------------------------------------------//