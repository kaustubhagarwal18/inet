//
// Copyright (C) 2008 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INET_IPv4ROUTE_H
#define __INET_IPv4ROUTE_H


#include "INETDefs.h"

#include "IPv4Address.h"

class InterfaceEntry;
class IRoutingTable;

/**
 * IPv4 route in IRoutingTable.
 *
 * @see IRoutingTable, RoutingTable
 */
class INET_API IPv4Route : public cObject
{
  public:
    /** Route type */
    enum RouteType
    {
        DIRECT,  ///< Directly attached to the router
        REMOTE   ///< Reached through another router
    };

    /** Specifies where the route comes from */
    enum RouteSource
    {
        MANUAL,       ///< manually added static route
        IFACENETMASK, ///< comes from an interface's netmask
        RIP,          ///< managed by the given routing protocol
        OSPF,         ///< managed by the given routing protocol
        BGP,          ///< managed by the given routing protocol
        ZEBRA,        ///< managed by the Quagga/Zebra based model
        MANET,        ///< managed by manet, search exact address
        MANET2,       ///< managed by manet, search approximate address
    };

  protected:
    IRoutingTable *rt;    ///< the routing table in which this route is inserted, or NULL
    IPv4Address dest;     ///< Destination
    IPv4Address netmask;  ///< Route mask
    IPv4Address gateway;  ///< Next hop
    InterfaceEntry *interfacePtr; ///< interface
    RouteType type;       ///< direct or remote
    RouteSource source;   ///< manual, routing prot, etc.
    int metric;           ///< Metric ("cost" to reach the destination)

  public:
    enum {F_DESTINATION, F_NETMASK, F_GATEWAY, F_IFACE, F_TYPE, F_SOURCE, F_METRIC, F_LAST}; // field codes for changed()

  private:
    // copying not supported: following are private and also left undefined
    IPv4Route(const IPv4Route& obj);
    IPv4Route& operator=(const IPv4Route& obj);

  protected:
    void changed(int fieldCode);

  public:
    IPv4Route();
    virtual ~IPv4Route() {}
    virtual std::string info() const;
    virtual std::string detailedInfo() const;

    /** To be called by the routing table when this route is added or removed from it */
    virtual void setRoutingTable(IRoutingTable *rt) {this->rt = rt;}
    IRoutingTable *getRoutingTable() {return rt;}

    /** test validity of route entry, e.g. check expiry */
    virtual bool isValid() const { return true; }

    virtual void setDestination(IPv4Address _dest)  { if (dest != _dest) {dest = _dest; changed(F_DESTINATION);} }
    virtual void setNetmask(IPv4Address _netmask)  { if (netmask != _netmask) {netmask = _netmask; changed(F_NETMASK);} }
    virtual void setGateway(IPv4Address _gateway)  { if (gateway != _gateway) {gateway = _gateway; changed(F_GATEWAY);} }
    virtual void setInterface(InterfaceEntry *_interfacePtr)  { if (interfacePtr != _interfacePtr) {interfacePtr = _interfacePtr; changed(F_IFACE);} }
    virtual void setType(RouteType _type)  { if (type != _type) {type = _type; changed(F_TYPE);} }
    virtual void setSource(RouteSource _source)  { if (source != _source) {source = _source; changed(F_SOURCE);} }
    virtual void setMetric(int _metric)  { if (metric != _metric) {metric = _metric; changed(F_METRIC);} }

    /** Destination address prefix to match */
    IPv4Address getDestination() const {return dest;}

    /** Represents length of prefix to match */
    IPv4Address getNetmask() const {return netmask;}

    /** Next hop address */
    IPv4Address getGateway() const {return gateway;}

    /** Next hop interface */
    InterfaceEntry *getInterface() const {return interfacePtr;}

    /** Convenience method */
    const char *getInterfaceName() const;

    /** Route type: Direct or Remote */
    RouteType getType() const {return type;}

    /** Source of route. MANUAL (read from file), from routing protocol, etc */
    RouteSource getSource() const {return source;}

    /** "Cost" to reach the destination */
    int getMetric() const {return metric;}
};

#endif // __INET_IPv4ROUTE_H

