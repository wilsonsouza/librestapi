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
*  Dependence: boost::asio
*/
#pragma once
#include <string>
#include <vector>
#include <memory>

namespace restapi
{
   enum status_code : int
   {
      unknown = 0,
      information_continue = 100,
      information_switching_protocols,
      information_processing,
      success_ok = 200,
      success_created,
      success_accepted,
      success_non_authoritative_information,
      success_no_content,
      success_reset_content,
      success_partial_content,
      success_multi_status,
      success_already_reported,
      success_im_used = 226,
      redirection_multiple_choices = 300,
      redirection_moved_permanently,
      redirection_found,
      redirection_see_other,
      redirection_not_modified,
      redirection_use_proxy,
      redirection_switch_proxy,
      redirection_temporary_redirect,
      redirection_permanent_redirect,
      client_error_bad_request = 400,
      client_error_unauthorized,
      client_error_payment_required,
      client_error_forbidden,
      client_error_not_found,
      client_error_method_not_allowed,
      client_error_not_acceptable,
      client_error_proxy_authentication_required,
      client_error_request_timeout,
      client_error_conflict,
      client_error_gone,
      client_error_length_required,
      client_error_precondition_failed,
      client_error_payload_too_large,
      client_error_uri_too_long,
      client_error_unsupported_media_type,
      client_error_range_not_satisfiable,
      client_error_expectation_failed,
      client_error_im_a_teapot,
      client_error_misdirection_required = 421,
      client_error_unprocessable_entity,
      client_error_locked,
      client_error_failed_dependency,
      client_error_upgrade_required = 426,
      client_error_precondition_required = 428,
      client_error_too_many_requests,
      client_error_request_header_fields_too_large = 431,
      client_error_unavailable_for_legal_reasons = 451,
      server_error_internal_server_error = 500,
      server_error_not_implemented,
      server_error_bad_gateway,
      server_error_service_unavailable,
      server_error_gateway_timeout,
      server_error_http_version_not_supported,
      server_error_variant_also_negotiates,
      server_error_insufficient_storage,
      server_error_loop_detected,
      server_error_not_extended = 510,
      server_error_network_authentication_required
   };
   //--------------------------------------------------------------------------------------------//
   namespace status
   {
      namespace code
      {
         using pair = std::pair<status_code, std::string>;
         using vector_pair = std::vector < pair >;
         using vector_pointer = std::shared_ptr<vector_pair>;
      }
   }
   //--------------------------------------------------------------------------------------------//
   static status::code::vector_pair const & get_status_code( );
   status_code search_status_code( const std::string & codename );
   std::shared_ptr<std::string> search_status_code( status_code code );
   bool transform_status_code_to_disk_file( std::string const & filename );
   /**/
} // namespace restapi