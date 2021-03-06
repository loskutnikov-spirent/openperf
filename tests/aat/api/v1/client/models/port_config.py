# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class PortConfig(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'bond': 'PortConfigBond',
        'dpdk': 'PortConfigDpdk'
    }

    attribute_map = {
        'bond': 'bond',
        'dpdk': 'dpdk'
    }

    def __init__(self, bond=None, dpdk=None):  # noqa: E501
        """PortConfig - a model defined in Swagger"""  # noqa: E501

        self._bond = None
        self._dpdk = None
        self.discriminator = None

        if bond is not None:
            self.bond = bond
        if dpdk is not None:
            self.dpdk = dpdk

    @property
    def bond(self):
        """Gets the bond of this PortConfig.  # noqa: E501


        :return: The bond of this PortConfig.  # noqa: E501
        :rtype: PortConfigBond
        """
        return self._bond

    @bond.setter
    def bond(self, bond):
        """Sets the bond of this PortConfig.


        :param bond: The bond of this PortConfig.  # noqa: E501
        :type: PortConfigBond
        """
        self._bond = bond

    @property
    def dpdk(self):
        """Gets the dpdk of this PortConfig.  # noqa: E501


        :return: The dpdk of this PortConfig.  # noqa: E501
        :rtype: PortConfigDpdk
        """
        return self._dpdk

    @dpdk.setter
    def dpdk(self, dpdk):
        """Sets the dpdk of this PortConfig.


        :param dpdk: The dpdk of this PortConfig.  # noqa: E501
        :type: PortConfigDpdk
        """
        self._dpdk = dpdk

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(PortConfig, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, PortConfig):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
