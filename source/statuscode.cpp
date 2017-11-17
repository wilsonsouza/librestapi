/*
*
*  librestapi c++11 Version 1.0
*
*
*  Created by Wilson.Souza
*  Copyright (C) 2017, WR DevInfo, All Rights Reserved.
*  Copyright (C) 2017, Tecsidel do Brasil, All Rights Reserved.
*
*  Description:
*  Last update:
*
*  Dependence: boost::asio, catch, kashmir, openssl
*/
#include <restapi_statuscode.hpp>
#include <vector>
#include <fstream>
#include <memory>
#include <map>
#include <json_builderjson.hpp>
//--------------------------------------------------------------------------------------------//
const restapi::statuscodequeue & restapi::getstatuscodes( )
{
   static std::vector<std::pair<statuscode, std::string>> code =
   {
      { statuscode::unknown, "" },
      { statuscode::information_continue, "100 Continue" },
      { statuscode::information_switching_protocols, "101 Switching Protocols" },
      { statuscode::information_processing, "102 Processing" },
      { statuscode::success_ok, "200 OK" },
      { statuscode::success_created, "201 Created" },
      { statuscode::success_accepted, "202 Accepted" },
      { statuscode::success_non_authoritative_information, "203 Non-Authoritative Information" },
      { statuscode::success_no_content, "204 No Content" },
      { statuscode::success_reset_content, "205 Reset Content" },
      { statuscode::success_partial_content, "206 Partial Content" },
      { statuscode::success_multi_status, "207 Multi-Status" },
      { statuscode::success_already_reported, "208 Already Reported" },
      { statuscode::success_im_used, "226 IM Used" },
      { statuscode::redirection_multiple_choices, "300 Multiple Choices" },
      { statuscode::redirection_moved_permanently, "301 Moved Permanently" },
      { statuscode::redirection_found, "302 Found" },
      { statuscode::redirection_see_other, "303 See Other" },
      { statuscode::redirection_not_modified, "304 Not Modified" },
      { statuscode::redirection_use_proxy, "305 Use Proxy" },
      { statuscode::redirection_switch_proxy, "306 Switch Proxy" },
      { statuscode::redirection_temporary_redirect, "307 Temporary Redirect" },
      { statuscode::redirection_permanent_redirect, "308 Permanent Redirect" },
      { statuscode::client_error_bad_request, "400 Bad Request" },
      { statuscode::client_error_unauthorized, "401 Unauthorized" },
      { statuscode::client_error_payment_required, "402 Payment Required" },
      { statuscode::client_error_forbidden, "403 Forbidden" },
      { statuscode::client_error_not_found, "404 Not Found" },
      { statuscode::client_error_method_not_allowed, "405 Method Not Allowed" },
      { statuscode::client_error_not_acceptable, "406 Not Acceptable" },
      { statuscode::client_error_proxy_authentication_required, "407 Proxy Authentication Required" },
      { statuscode::client_error_request_timeout, "408 Request Timeout" },
      { statuscode::client_error_conflict, "409 Conflict" },
      { statuscode::client_error_gone, "410 Gone" },
      { statuscode::client_error_length_required, "411 Length Required" },
      { statuscode::client_error_precondition_failed, "412 Precondition Failed" },
      { statuscode::client_error_payload_too_large, "413 Payload Too Large" },
      { statuscode::client_error_uri_too_long, "414 URI Too Long" },
      { statuscode::client_error_unsupported_media_type, "415 Unsupported Media Type" },
      { statuscode::client_error_range_not_satisfiable, "416 Range Not Satisfiable" },
      { statuscode::client_error_expectation_failed, "417 Expectation Failed" },
      { statuscode::client_error_im_a_teapot, "418 I'm a teapot" },
      { statuscode::client_error_misdirection_required, "421 Misdirected Request" },
      { statuscode::client_error_unprocessable_entity, "422 Unprocessable Entity" },
      { statuscode::client_error_locked, "423 Locked" },
      { statuscode::client_error_failed_dependency, "424 Failed Dependency" },
      { statuscode::client_error_upgrade_required, "426 Upgrade Required" },
      { statuscode::client_error_precondition_required, "428 Precondition Required" },
      { statuscode::client_error_too_many_requests, "429 Too Many Requests" },
      { statuscode::client_error_request_header_fields_too_large, "431 Request Header Fields Too Large" },
      { statuscode::client_error_unavailable_for_legal_reasons, "451 Unavailable For Legal Reasons" },
      { statuscode::server_error_internal_server_error, "500 Internal Server Error" },
      { statuscode::server_error_not_implemented, "501 Not Implemented" },
      { statuscode::server_error_bad_gateway, "502 Bad Gateway" },
      { statuscode::server_error_service_unavailable, "503 Service Unavailable" },
      { statuscode::server_error_gateway_timeout, "504 Gateway Timeout" },
      { statuscode::server_error_http_version_not_supported, "505 HTTP Version Not Supported" },
      { statuscode::server_error_variant_also_negotiates, "506 Variant Also Negotiates" },
      { statuscode::server_error_insufficient_storage, "507 Insufficient Storage" },
      { statuscode::server_error_loop_detected, "508 Loop Detected" },
      { statuscode::server_error_not_extended, "510 Not Extended" },
      { statuscode::server_error_network_authentication_required, "511 Network Authentication Required" }
   };
   return code;
}
//--------------------------------------------------------------------------------------------//
restapi::statuscode restapi::searchstatuscode( const std::string & codename )
{
   for( auto &status_code : getstatuscodes( ) )
   {
      if( status_code.second == codename )
      {
         return status_code.first;
      }
   }
   return restapi::statuscode::unknown;
}
//--------------------------------------------------------------------------------------------//
const std::string & restapi::searchstatuscode( restapi::statuscode code )
{
   for( auto &status_code : getstatuscodes( ) )
   {
      if( status_code.first == code )
      {
         return status_code.second;
      }
   }
   return getstatuscodes( )[ 0 ].second;
}
//--------------------------------------------------------------------------------------------//
bool restapi::transformstatuscodetodiskfile( const std::string filename )
{
   auto of = std::shared_ptr<std::fstream>( new std::fstream( ) );
   {
      of->open( filename.c_str( ), std::fstream::out | std::fstream::app );

      if( !of->is_open( ) )
      {
         throw std::runtime_error( std::string( "Cann´t create file " + filename + "!" ) );
      }

      builderjson queue = { "tag", filename };

      for( auto && value : restapi::getstatuscodes( ) )
      {
         builderjson rows = std::multimap<std::string, std::string>
         {
            {"error", std::to_string( int( value.first ) ) },
            {"message", value.second}
         };
         queue[ "tag" ].push_back(rows);
      }
      //
      of.operator*() << queue.dump( );
   }
   return true;
}
//--------------------------------------------------------------------------------------------//
