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
*  Dependences: boost::asio, restbed framework
*/
#pragma warning(disable: 4101) //disable warning to const local reference
#include <json_builderjson.hpp>
#include <restapi_status_code.hpp>
#include <fstream>
//--------------------------------------------------------------------------------------------//
restapi::status::code::vector_pair const & restapi::get_status_code( )
{
   static status::code::vector_pair code =
   {
      { status_code::unknown, "" },
      { status_code::information_continue, "100 Continue" },
      { status_code::information_switching_protocols, "101 Switching Protocols" },
      { status_code::information_processing, "102 Processing" },
      { status_code::success_ok, "200 OK" },
      { status_code::success_created, "201 Created" },
      { status_code::success_accepted, "202 Accepted" },
      { status_code::success_non_authoritative_information, "203 Non-Authoritative Information" },
      { status_code::success_no_content, "204 No Content" },
      { status_code::success_reset_content, "205 Reset Content" },
      { status_code::success_partial_content, "206 Partial Content" },
      { status_code::success_multi_status, "207 Multi-Status" },
      { status_code::success_already_reported, "208 Already Reported" },
      { status_code::success_im_used, "226 IM Used" },
      { status_code::redirection_multiple_choices, "300 Multiple Choices" },
      { status_code::redirection_moved_permanently, "301 Moved Permanently" },
      { status_code::redirection_found, "302 Found" },
      { status_code::redirection_see_other, "303 See Other" },
      { status_code::redirection_not_modified, "304 Not Modified" },
      { status_code::redirection_use_proxy, "305 Use Proxy" },
      { status_code::redirection_switch_proxy, "306 Switch Proxy" },
      { status_code::redirection_temporary_redirect, "307 Temporary Redirect" },
      { status_code::redirection_permanent_redirect, "308 Permanent Redirect" },
      { status_code::client_error_bad_request, "400 Bad Request" },
      { status_code::client_error_unauthorized, "401 Unauthorized" },
      { status_code::client_error_payment_required, "402 Payment Required" },
      { status_code::client_error_forbidden, "403 Forbidden" },
      { status_code::client_error_not_found, "404 Not Found" },
      { status_code::client_error_method_not_allowed, "405 Method Not Allowed" },
      { status_code::client_error_not_acceptable, "406 Not Acceptable" },
      { status_code::client_error_proxy_authentication_required, "407 Proxy Authentication Required" },
      { status_code::client_error_request_timeout, "408 Request Timeout" },
      { status_code::client_error_conflict, "409 Conflict" },
      { status_code::client_error_gone, "410 Gone" },
      { status_code::client_error_length_required, "411 Length Required" },
      { status_code::client_error_precondition_failed, "412 Precondition Failed" },
      { status_code::client_error_payload_too_large, "413 Payload Too Large" },
      { status_code::client_error_uri_too_long, "414 URI Too Long" },
      { status_code::client_error_unsupported_media_type, "415 Unsupported Media Type" },
      { status_code::client_error_range_not_satisfiable, "416 Range Not Satisfiable" },
      { status_code::client_error_expectation_failed, "417 Expectation Failed" },
      { status_code::client_error_im_a_teapot, "418 I'm a teapot" },
      { status_code::client_error_misdirection_required, "421 Misdirected Request" },
      { status_code::client_error_unprocessable_entity, "422 Unprocessable Entity" },
      { status_code::client_error_locked, "423 Locked" },
      { status_code::client_error_failed_dependency, "424 Failed Dependency" },
      { status_code::client_error_upgrade_required, "426 Upgrade Required" },
      { status_code::client_error_precondition_required, "428 Precondition Required" },
      { status_code::client_error_too_many_requests, "429 Too Many Requests" },
      { status_code::client_error_request_header_fields_too_large, "431 Request Header Fields Too Large" },
      { status_code::client_error_unavailable_for_legal_reasons, "451 Unavailable For Legal Reasons" },
      { status_code::server_error_internal_server_error, "500 Internal Server Error" },
      { status_code::server_error_not_implemented, "501 Not Implemented" },
      { status_code::server_error_bad_gateway, "502 Bad Gateway" },
      { status_code::server_error_service_unavailable, "503 Service Unavailable" },
      { status_code::server_error_gateway_timeout, "504 Gateway Timeout" },
      { status_code::server_error_http_version_not_supported, "505 HTTP Version Not Supported" },
      { status_code::server_error_variant_also_negotiates, "506 Variant Also Negotiates" },
      { status_code::server_error_insufficient_storage, "507 Insufficient Storage" },
      { status_code::server_error_loop_detected, "508 Loop Detected" },
      { status_code::server_error_not_extended, "510 Not Extended" },
      { status_code::server_error_network_authentication_required, "511 Network Authentication Required" }
   };
   return code;
}
//--------------------------------------------------------------------------------------------//
restapi::status_code restapi::search_status_code( const std::string & codename )
{
   for( auto &status_code : get_status_code( ) )
   {
      if( status_code.second == codename )
      {
         return status_code.first;
      }
   }
   return restapi::status_code::unknown;
}
//--------------------------------------------------------------------------------------------//
std::shared_ptr<std::string> restapi::search_status_code( restapi::status_code code )
{
   auto queue = get_status_code( );
   /**/
   for( auto &status_code : queue )
   {
      if( status_code.first == code )
      {
         return std::make_shared<std::string>( status_code.second );
      }
   }
   return std::make_shared<std::string>( queue[ 0 ].second );
}
//--------------------------------------------------------------------------------------------//
bool restapi::transform_status_code_to_disk_file( std::string const & filename )
{
   try
   {
      auto of = std::shared_ptr<std::fstream>( new std::fstream( ) );
      {
         of->open( filename.c_str( ), std::fstream::out | std::fstream::app );

         if( !of->is_open( ) )
         {
            throw std::runtime_error( std::string( "Cann´t create file " + filename + "!" ) );
         }

         std::json::value queue;
         /**/
         queue[ "filename" ] = filename;
         /**/
         for( auto && value : restapi::get_status_code( ) )
         {
            auto rows = std::multimap<std::string, std::string>( );
            {
               rows.emplace( std::make_pair( "error", std::to_string( int( value.first ) ) ) );
               rows.emplace( std::make_pair( "message", value.second ) );
            }
            queue[ "tag" ] = rows;
         }
         //
         of.operator*( ) << queue.dump( 0 );
      }
   }
   catch( std::exception const & e )
   {
      throw e;
   }
   return true;
}
//--------------------------------------------------------------------------------------------//