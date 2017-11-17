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
#include <restbed>
//--------------------------------------------------------------------------------------------//
namespace restapi
{
   class response_impl : public restbed::Response
   {
   public:
      using pointer = Response::pointer;
      using pointer_const = Response::pointer_const;
      using const_pointer_const = Response::const_pointer_const;
   public:
      response_impl( ) = default;
   };
   //--------------------------------------------------------------------------------------------//
   class resquest_impl : public restbed::Request
   {
   public:
      using pointer = Request::pointer;
      using pointer_const = Request::pointer_const;
      using const_pointer_const = Request::const_pointer_const;
   public:
      resquest_impl( ) = default;
   };
   //--------------------------------------------------------------------------------------------//
   class session_impl : public restbed::Session
   {
   public:
      using pointer = Session::pointer;
      using pointer_const = Session::pointer_const;
      using const_pointer_const = Session::const_pointer_const;
   public:
      session_impl( ) = default;
      session_impl( std::string const &  id ) :Session( id )
      {
      }
   };
   //--------------------------------------------------------------------------------------------//
   class session_manager_impl : public restbed::SessionManager
   {
   public:
      using pointer = SessionManager::pointer;
      using pointer_const = SessionManager::pointer_const;
      using const_pointer_const = SessionManager::const_pointer_const;
   public:
      session_manager_impl( ) = default;
   };
   //--------------------------------------------------------------------------------------------//
   namespace methods
   {
      static std::string const get = "GET";
      static std::string const post = "POST";
      static std::string const put = "PUT";
      static std::string const options = "OPTIONS";
      static std::string const head = "HEAD";
      static std::string const Delete = "DELETE";
      static std::string const patch = "PATCH";
      static std::string const merge = "MERGE";
      static std::string const trace = "TRACE";
   }
   //--------------------------------------------------------------------------------------------//
   class resource_impl : public restbed::Resource
   {
   public:
      using pointer = std::shared_ptr<resource_impl>;
      using pointer_const = pointer const;
      using const_pointer_const = const std::shared_ptr<const resource_impl>;
      using stack_pointer = std::shared_ptr<std::vector<pointer>>;
      using rules_map = std::multimap<std::string, std::string>;
   protected:
      std::string m_url = std::string( );
      std::string m_method_bind = std::string( );
   public:
      resource_impl( const std::string & resource_name );
      virtual void on_get( const session_impl::pointer session ) = 0;
      virtual void on_put( const session_impl::pointer session ) = 0;
      virtual void on_post( const session_impl::pointer session ) = 0;
      virtual void on_options( const session_impl::pointer session ) = 0;
      virtual void on_head( const session_impl::pointer session ) = 0;
      virtual void on_delete( const session_impl::pointer session ) = 0;
      virtual void on_patch( const session_impl::pointer session ) = 0;
      virtual void on_merge( const session_impl::pointer session ) = 0;
      virtual void on_trace( const session_impl::pointer session ) = 0;
      virtual void on_prepare_method_router( );
      virtual void start( );
      virtual std::string const & get_url( );
      virtual std::string const & get_method_bind( );
   protected:
      virtual void bind( std::string const & method_name,
                         std::function<void( const session_impl::pointer )> const & bind_func,
                         rules_map const & rules = rules_map{} );
   };
}
//--------------------------------------------------------------------------------------------//