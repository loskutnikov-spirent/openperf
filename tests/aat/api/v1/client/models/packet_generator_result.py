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


class PacketGeneratorResult(object):
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
        'id': 'str',
        'generator_id': 'str',
        'active': 'bool',
        'flow_counters': 'PacketGeneratorFlowCounters',
        'flows': 'list[str]',
        'remaining': 'DurationRemainder'
    }

    attribute_map = {
        'id': 'id',
        'generator_id': 'generator_id',
        'active': 'active',
        'flow_counters': 'flow_counters',
        'flows': 'flows',
        'remaining': 'remaining'
    }

    def __init__(self, id=None, generator_id=None, active=None, flow_counters=None, flows=None, remaining=None):  # noqa: E501
        """PacketGeneratorResult - a model defined in Swagger"""  # noqa: E501

        self._id = None
        self._generator_id = None
        self._active = None
        self._flow_counters = None
        self._flows = None
        self._remaining = None
        self.discriminator = None

        self.id = id
        if generator_id is not None:
            self.generator_id = generator_id
        self.active = active
        self.flow_counters = flow_counters
        self.flows = flows
        if remaining is not None:
            self.remaining = remaining

    @property
    def id(self):
        """Gets the id of this PacketGeneratorResult.  # noqa: E501

        Unique generator result identifier  # noqa: E501

        :return: The id of this PacketGeneratorResult.  # noqa: E501
        :rtype: str
        """
        return self._id

    @id.setter
    def id(self, id):
        """Sets the id of this PacketGeneratorResult.

        Unique generator result identifier  # noqa: E501

        :param id: The id of this PacketGeneratorResult.  # noqa: E501
        :type: str
        """
        self._id = id

    @property
    def generator_id(self):
        """Gets the generator_id of this PacketGeneratorResult.  # noqa: E501

        Unique generator identifier that produced this result  # noqa: E501

        :return: The generator_id of this PacketGeneratorResult.  # noqa: E501
        :rtype: str
        """
        return self._generator_id

    @generator_id.setter
    def generator_id(self, generator_id):
        """Sets the generator_id of this PacketGeneratorResult.

        Unique generator identifier that produced this result  # noqa: E501

        :param generator_id: The generator_id of this PacketGeneratorResult.  # noqa: E501
        :type: str
        """
        self._generator_id = generator_id

    @property
    def active(self):
        """Gets the active of this PacketGeneratorResult.  # noqa: E501

        Indicates whether this result is currently being updated  # noqa: E501

        :return: The active of this PacketGeneratorResult.  # noqa: E501
        :rtype: bool
        """
        return self._active

    @active.setter
    def active(self, active):
        """Sets the active of this PacketGeneratorResult.

        Indicates whether this result is currently being updated  # noqa: E501

        :param active: The active of this PacketGeneratorResult.  # noqa: E501
        :type: bool
        """
        self._active = active

    @property
    def flow_counters(self):
        """Gets the flow_counters of this PacketGeneratorResult.  # noqa: E501


        :return: The flow_counters of this PacketGeneratorResult.  # noqa: E501
        :rtype: PacketGeneratorFlowCounters
        """
        return self._flow_counters

    @flow_counters.setter
    def flow_counters(self, flow_counters):
        """Sets the flow_counters of this PacketGeneratorResult.


        :param flow_counters: The flow_counters of this PacketGeneratorResult.  # noqa: E501
        :type: PacketGeneratorFlowCounters
        """
        self._flow_counters = flow_counters

    @property
    def flows(self):
        """Gets the flows of this PacketGeneratorResult.  # noqa: E501

        List of unique flow ids included in stats. Individual flow statistics may be queried via the `tx-flows` endpoint.   # noqa: E501

        :return: The flows of this PacketGeneratorResult.  # noqa: E501
        :rtype: list[str]
        """
        return self._flows

    @flows.setter
    def flows(self, flows):
        """Sets the flows of this PacketGeneratorResult.

        List of unique flow ids included in stats. Individual flow statistics may be queried via the `tx-flows` endpoint.   # noqa: E501

        :param flows: The flows of this PacketGeneratorResult.  # noqa: E501
        :type: list[str]
        """
        self._flows = flows

    @property
    def remaining(self):
        """Gets the remaining of this PacketGeneratorResult.  # noqa: E501


        :return: The remaining of this PacketGeneratorResult.  # noqa: E501
        :rtype: DurationRemainder
        """
        return self._remaining

    @remaining.setter
    def remaining(self, remaining):
        """Sets the remaining of this PacketGeneratorResult.


        :param remaining: The remaining of this PacketGeneratorResult.  # noqa: E501
        :type: DurationRemainder
        """
        self._remaining = remaining

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
        if issubclass(PacketGeneratorResult, dict):
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
        if not isinstance(other, PacketGeneratorResult):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other