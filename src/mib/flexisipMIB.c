/*
 * Note: this file originally auto-generated by mib2c using
 *        mib2c.flexisip.conf
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "flexisipMIB.h"
#include "configmanager.hh"
#include "agent.hh"
#include "module-registrar.hh"
ConfigManager* cm;
Agent* ag;
/** Initializes the flexisipMIB module */
void
init_flexisipMIB(Agent& agent, ConfigManager& aCm)
{
    const oid autoRespawn_oid[] = { 1,3,6,1,4,1,100000,1,1,1,1 };
    const oid aliases_oid[] = { 1,3,6,1,4,1,100000,1,1,1,2 };
    const oid ipAddress_oid[] = { 1,3,6,1,4,1,100000,1,1,1,3 };
    const oid bindAddress_oid[] = { 1,3,6,1,4,1,100000,1,1,1,4 };
    const oid port_oid[] = { 1,3,6,1,4,1,100000,1,1,1,5 };
    const oid transportUris_oid[] = { 1,3,6,1,4,1,100000,1,2,1,1 };
    const oid totalNumberOfAddedRecords_oid[] = { 1,3,6,1,4,1,100000,1,2,2,1,1 };
    const oid totalNumberOfExpiredRecords_oid[] = { 1,3,6,1,4,1,100000,1,2,2,1,2 };

  DEBUGMSGTL(("flexisipMIB", "Initializing\n"));
  cm=&aCm;
  ag=&agent;
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("autoRespawn", handle_autoRespawn,
                               autoRespawn_oid, OID_LENGTH(autoRespawn_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("aliases", handle_aliases,
                               aliases_oid, OID_LENGTH(aliases_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("ipAddress", handle_ipAddress,
                               ipAddress_oid, OID_LENGTH(ipAddress_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("bindAddress", handle_bindAddress,
                               bindAddress_oid, OID_LENGTH(bindAddress_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("port", handle_port,
                               port_oid, OID_LENGTH(port_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("transportUris", handle_transportUris,
                               transportUris_oid, OID_LENGTH(transportUris_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("totalNumberOfAddedRecords", handle_totalNumberOfAddedRecords,
                               totalNumberOfAddedRecords_oid, OID_LENGTH(totalNumberOfAddedRecords_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("totalNumberOfExpiredRecords", handle_totalNumberOfExpiredRecords,
                               totalNumberOfExpiredRecords_oid, OID_LENGTH(totalNumberOfExpiredRecords_oid),
                               HANDLER_CAN_RONLY
        ));
}

int
handle_autoRespawn(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_integer(requests->requestvb, ASN_INTEGER,
            		cm->getGlobal()->get<ConfigBoolean>("auto-respawn")->read());
            
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_autoRespawn\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_aliases(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
            		cm->getGlobal()->get<ConfigStringList>("aliases")->get().c_str(),
            		cm->getGlobal()->get<ConfigStringList>("aliases")->get().size());
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_aliases\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_ipAddress(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
            		cm->getGlobal()->get<ConfigString>("ip-address")->get().c_str(),
            		cm->getGlobal()->get<ConfigString>("ip-address")->get().size());
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_ipAddress\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_bindAddress(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
            		cm->getGlobal()->get<ConfigString>("bind-address")->get().c_str(),
            		cm->getGlobal()->get<ConfigString>("bind-address")->get().size());
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_bindAddress\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_port(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_integer(requests->requestvb, ASN_INTEGER,
            		cm->getGlobal()->get<ConfigInt>("port")->read());
            
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_port\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_transportUris(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     ag->getTransportUri().c_str(),
                                     ag->getTransportUri().size());
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_transportUris\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_totalNumberOfAddedRecords(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    switch(reqinfo->mode) {
        case MODE_GET: {
            unsigned long value = dynamic_cast<RegistrarMgt&>(ag->getModuleByName("Registrar")).getTotalNumberOfAddedRecords();
			struct counter64 conter;
			conter.high=value>>32;
			conter.low=value&0xFFFFFFFF;
			snmp_set_var_typed_value(requests->requestvb, ASN_COUNTER64,&conter,sizeof(conter));
            break;
        }

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_totalNumberOfAddedRecords\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }
    return SNMP_ERR_NOERROR;
}
int
handle_totalNumberOfExpiredRecords(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {


        case MODE_GET:{
            unsigned long value = dynamic_cast<RegistrarMgt&>(ag->getModuleByName("Registrar")).getTotalNumberOfExpiredRecords();
            struct counter64 conter;
			conter.high=value>>32;
			conter.low=value&0x00000000FFFFFFFF;
			snmp_set_var_typed_value(requests->requestvb, ASN_COUNTER64,&conter,sizeof(conter));
            
            break;
        }

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_totalNumberOfExpiredRecords\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}