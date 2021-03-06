
# Dynamic Results

OpenPerf generators _may_ be configured to record optional test results during test runs. There are two types of optional results: threshold counters and [t-digests](https://github.com/tdunning/t-digest/blob/master/docs/t-digest-paper/histo.pdf).

## API

Generators can be configured to use Dynamic Results at generator time start. All generators that support Dynamic Results use the same API request and response structure described in that document. However, not all generators support Dynamic Results. Please, see the generator documentation for more information and list of available field names.

## Configuration

Dynamic Results configuration consists of the Threshold and T-Digest configuration arrays. The arrays are optional and can be absent.

```json
{
    "thresholds": [
        {
            "id": "",
            "value": 1000.0,
            "function": "dx",
            "stat_x": "read.bytes_actual",
            "condition": "less"
        }
    ],
    "tdigests": [
        {
            "id": "",
            "function": "dx",
            "stat_x": "read.bytes_actual",
            "compression": 10
        }
    ]
}
```

## Thresholds

Threshold counters evaluate a mathematical relation between a threshold and a statistic. Threshold compares the result of *function* and the *value* using *condition*. The result of the comparison increases an appropriate counter, *condition_true* or *condition_false*.

### Configuration

```json
{
    "id": "",
    "value": 1000.0,
    "function": "dxdy",
    "stat_x": "read.bytes_actual",
    "stat_y": "read.ops_actual",
    "condition": "less"
}
```

* **id** - The unique threshold identifier. If empty, then UUID identifier will be generated by dynamic results itself.
* **value** - The value of interest.
* **function** - The function what applies to statistics points.
* **condition** - The condition that will applied to *value* and the result of the *function*.
* **stat_x** - The name of the field of the statistics data.
* **stat_y** - The name of the field of the statistics data. Optional value, applicable for *dxdy* function only.

Conditions:
* **less**
* **less_or_equal**
* **greater**
* **greater_or_equal**
* **equal**

Functions:
* **dx** - the difference between *stat_x* values.
* **dxdy** - the difference between *stat_x* values divided by the difference between *stat_y* values.
* **dxdt** - the difference between *stat_x* values divided by the number of nanoseconds between the two measurements.

### Result
```json
{
    "condition": "less",
    "condition_false": 1229,
    "condition_true": 1229,
    "function": "dx",
    "id": "first",
    "stat_x": "read.bytes_actual",
    "value": 1000.0
}
```

* **id** - The unique identifier of the threshold from configuration or generated value.
* **value** - The configured value of the interest.
* **function** - The configured function.
* **condition** - The configured condition.
* **stat_x** - The field name of the statistics data from configuration.
* **stat_y** - The field name of the statistics data from configuration. Only for *dxdy* function.
* **condition_true** - The count of the measurements for which *condition* was *true*.
* **condition_false** - The count of the measurements for which *condition* was *false*.

## T-Digests

T-Digests summarize all of the recorded data points for a statistic.  This data may then be
used to generate histogram or determine approximate probabilities.

### Configuration

```json
{
    "id": "",
    "function": "dxdy",
    "stat_x": "read.bytes_actual",
    "stat_y": "read.ops_actual",
    "compression": 10
}
```

Fields:
* **id** - The unique threshold identifier. If empty, then UUID identifier will be generated by dynamic results itself.
* **compression** - The compression factor of the T-Digest.
* **function** - The function what applies to statistics points.
* **stat_x** - The name of the field of the statistics data.
* **stat_y** - The name of the field of the statistics data. Optional value, applicable for *dxdy* function only.

Functions:
* **dx** - the difference between *stat_x* values.
* **dxdy** - the difference between *stat_x* values divided by the difference between *stat_y* values.
* **dxdt** - the difference between *stat_x* values divided by the number of nanoseconds between the two measurements.

### Result

```json
{
    "centroids": [
        {
            "mean": 0.0,
            "weight": 313
        },
        {
            "mean": 9579.742086752645,
            "weight": 1706
        },
        {
            "mean": 20855.868235294125,
            "weight": 425
        },
        {
            "mean": 22528.0,
            "weight": 6
        }
    ],
    "compression": 10,
    "function": "dx",
    "id": "a0eacc4a-0de0-4761-5889-19701765b577",
    "stat_x": "read.bytes_actual"
}
```

* **id** - The unique identifier of the threshold from configuration or generated value.
* **compression** - The configured compression.
* **function** - The configured function.
* **stat_x** - The field name of the statistics data from configuration.
* **stat_y** - The field name of the statistics data from configuration. Only for *dxdy* function.
* **centroids** - The array of centroids.
   * **mean** - The mean value.
   * **weight** - The weight of mean value.

